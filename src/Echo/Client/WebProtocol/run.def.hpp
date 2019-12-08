template <typename InterfaceInputStream, typename InterfaceOutputStream>
template <typename InputStream, typename OutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	std::variant <std::unique_ptr <WebSocketProtocol>, HTTP::Response::T>
	upgrade_response;

	{
		Thread::Nursery::Aggregate::T
		(
			std::forward_as_tuple
			(
				this -> m_http_protocol,
				[&] ()
				{
					this -> m_http_protocol . run (input_stream, output_stream);
				}
			),
			std::forward_as_tuple
			(
				nullptr,
				[&] ()
				{
					upgrade_response =
						this -> m_http_protocol .
						template upgrade <WebSocketProtocol>
						(
							std::forward_as_tuple (this -> m_uri),
							std::forward_as_tuple
							(
								this -> m_websocket_config,
								this -> m_interface_input_stream,
								this -> m_interface_output_stream
							)
						);

					if (upgrade_response . index () == 1)
					{
						throw Failure::ServiceError::T
						(
							"Server declined to switch protocols\n" +
							std::get <1> (upgrade_response) . head ()
						);
					}
				}
			)
		);
	}

	// We've got a new protocol.  Now to prime and run it.

	WebSocketProtocol & websocket_protocol = * std::get <0> (upgrade_response);

	websocket_protocol . prime ();

	Scope::T websocket_cancel_scope
	(
		this -> m_websocket_cancel_slot,
		websocket_protocol
	);

	websocket_protocol . run (input_stream, output_stream);
}

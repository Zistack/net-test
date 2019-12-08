template <typename InterfaceInputStream, typename InterfaceOutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::event ()
{
	WebSocket::Message::T message (WebSocket::Type::TEXT);

	message . withWriter
	(
		[&] (auto && output_stream)
		{
			while
			(
				! IO::Util::test
				(
					std::forward <InterfaceInputStream>
					(
						this -> m_interface_input_stream
					),
					'\n'
				)
			)
			{
				output_stream . put (this -> m_interface_input_stream . get ());
			}
			this -> m_interface_input_stream . get ();
		}
	);

	this -> webSocketProtocol () . send (std::move (message));
}

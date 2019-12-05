template <typename InterfaceInputStream, typename InterfaceOutputStream>
struct T
{
	T
	(
		const URI::T & uri,
		const HTTP::Client::Config::T & http_config,
		const WebSocket::Config::T & websocket_config,
		InterfaceInputStream interface_input_stream,
		InterfaceOutputStream interface_output_stream
	);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;

private:

	using WebSocketProtocol =
		WebSocketProtocol::T <InterfaceInputStream, InterfaceOutputStream>;

	// Given members

	URI::T m_uri;
	const WebSocket::Config::T m_websocket_config;
	InterfaceInputStream m_interface_input_stream;
	InterfaceOutputStream m_interface_output_stream;

	// Internal members

	HTTP::Client::Protocol::T m_http_protocol;
	Failure::CancellableSlot::T <WebSocketProtocol> m_websocket_cancel_slot;

	Failure::CancellableAggregate::T
	<
		HTTP::Client::Protocol::T,
		Failure::CancellableSlot::T <WebSocketProtocol>
	>
	m_cancellable;
};

template <typename InterfaceInputStream, typename InterfaceOutputStream>
T
(
	const URI::T & uri,
	const HTTP::Client::Config::T & http_config,
	const WebSocket::Config::T & websocket_config,
	InterfaceInputStream && interface_input_stream,
	InterfaceOutputStream && interface_output_stream
) ->
	T <InterfaceInputStream, InterfaceOutputStream>;

template <typename InterfaceInputStream, typename InterfaceOutputStream>
T <InterfaceInputStream, InterfaceOutputStream>::T
(
	const WebSocket::Client::RequestFactory::T & request_factory,
	const HTTP::Response::T & response,
	const WebSocket::Config::T & websocket_config,
	InterfaceInputStream interface_input_stream,
	InterfaceOutputStream interface_output_stream
)
:	WebSocketInterface::T <InterfaceOutputStream>
	(
		request_factory,
		response,
		websocket_config,
		interface_output_stream
	),
	m_interface_input_stream (interface_input_stream)
{
}

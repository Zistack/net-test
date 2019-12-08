template <typename InterfaceInputStream, typename InterfaceOutputStream>
T <InterfaceInputStream, InterfaceOutputStream>::T
(
	const T::ProtocolData & protocol_data,
	const HTTP::Response::T & response,
	const WebSocket::Config::T & websocket_config,
	InterfaceInputStream interface_input_stream,
	InterfaceOutputStream interface_output_stream
)
:	WebSocketInterface::T <InterfaceOutputStream>
	(
		protocol_data,
		response,
		websocket_config,
		interface_output_stream
	),
	m_interface_input_stream (interface_input_stream)
{
}

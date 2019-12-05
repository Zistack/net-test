template <typename InterfaceInputStream, typename InterfaceOutputStream>
T <InterfaceInputStream, InterfaceOutputStream>::T
(
	const URI::T & uri,
	const HTTP::Client::Config::T & http_config,
	const WebSocket::Config::T & websocket_config,
	InterfaceInputStream interface_input_stream,
	InterfaceOutputStream interface_output_stream
)
:	m_uri (uri),
	m_websocket_config (websocket_config),
	m_interface_input_stream (interface_input_stream),
	m_interface_output_stream (interface_output_stream),
	m_http_protocol (http_config),
	m_cancellable (this -> m_http_protocol, this -> m_websocket_cancel_slot)
{
}

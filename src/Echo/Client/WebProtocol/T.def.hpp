template <typename InterfaceInputStream, typename InterfaceOutputStream>
T <InterfaceInputStream, InterfaceOutputStream>::T
(
	const Config::T & config,
	InterfaceInputStream interface_input_stream,
	InterfaceOutputStream interface_output_stream
)
:	m_uri (config . uri ()),
	m_websocket_config (config . webSocketConfig ()),
	m_interface_input_stream (interface_input_stream),
	m_interface_output_stream (interface_output_stream),
	m_http_protocol (config . httpConfig ()),
	m_cancellable (this -> m_http_protocol, this -> m_websocket_cancel_slot)
{
}

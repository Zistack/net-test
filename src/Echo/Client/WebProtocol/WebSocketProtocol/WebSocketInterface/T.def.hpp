template <typename OutputStream>
T <OutputStream>::T
(
	const T::ProtocolData & protocol_data,
	const HTTP::Response::T & response,
	const WebSocket::Config::T & websocket_config,
	OutputStream output_stream
)
:	WebSocket::Client::Protocol::T <T <OutputStream>>
	(
		protocol_data,
		response,
		websocket_config
	),
	m_output_stream (std::forward <OutputStream> (output_stream))
{
}

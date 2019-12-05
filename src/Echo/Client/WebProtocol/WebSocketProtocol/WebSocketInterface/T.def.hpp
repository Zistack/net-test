template <typename OutputStream>
T <OutputStream>::T
(
	const WebSocket::Client::RequestFactory::T & request_factory,
	const HTTP::Response::T & response,
	const WebSocket::Config::T & websocket_config,
	OutputStream output_stream
)
:	WebSocket::Client::Protocol::T <T <OutputStream>>
	(
		request_factory,
		response,
		websocket_config
	),
	m_output_stream (std::forward <OutputStream> (output_stream))
{
}

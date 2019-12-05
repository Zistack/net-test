template <typename OutputStream>
struct T : WebSocket::Client::Protocol::T <T <OutputStream>>
{
	void
	pong (std::vector <uint8_t> && payload);

	void
	dispatch (WebSocket::Message::T && message);

protected:

	T
	(
		const WebSocket::Client::RequestFactory::T & request_factory,
		const HTTP::Response::T & response,
		const WebSocket::Config::T & websocket_config,
		OutputStream output_stream
	);

	~T () = default;

private:

	OutputStream m_output_stream;
};

template <typename OutputStream>
T (OutputStream && output_stream) -> T <OutputStream>;

struct T : WebSocket::Server::Connection::Protocol::T <T, true>
{
	void
	pong (std::vector <uint8_t> && payload);

	void
	dispatch (WebSocket::Message::T && message);

protected:

	using WebSocket::Server::Connection::Protocol::T <T, true>::T;

	~T () = default;
};

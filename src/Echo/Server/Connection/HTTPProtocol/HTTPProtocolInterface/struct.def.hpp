struct T : HTTP::Server::Connection::Protocol::T <T, WebSocketProtocol::T>
{
	HTTP::Response::T
	respond (const HTTP::Request::T & request);

protected:

	using HTTP::Server::Connection::Protocol::T <T, WebSocketProtocol::T>::T;

	~T () = default;
};

using T = IO::ServerProtocol::T
<
	Connection::HTTPProtocol::T,
	const HTTP::Server::Config::T &,
	std::pair
	<
		std::tuple <>,
		std::tuple <const WebSocket::Config::T &>
	>
>;

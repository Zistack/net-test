using T = IO::ServerProtocol::T
<
	Connection::HTTPProtocol::T,
	HTTP::Server::Config::T,
	std::optional <HTTP::HostData::T>,
	std::pair
	<
		std::tuple <>,
		std::tuple <const WebSocket::Config::T>
	>
>;

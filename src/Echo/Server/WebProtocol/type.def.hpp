using T = IO::ServerProtocol::T
<
	Connection::HTTPProtocol::T,
	const HTTP::Server::Config::T &,
	std::pair
	<
		std::tuple <>,
		std::tuple
		<
			const HTTP::Request::T &,
			const Connection::WebSocketProtocol::T::ResponseFactory &,
			const WebSocket::Config::T &
		>
	>
>;

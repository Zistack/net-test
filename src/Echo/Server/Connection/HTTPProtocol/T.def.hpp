T::T
(
	const HTTP::Server::Config::T & config,
	const std::pair <std::tuple <>, std::tuple <const WebSocket::Config::T &>> &
		upgrade_arguments
)
:	HTTPProtocolInterface::T (config, upgrade_arguments)
{
}

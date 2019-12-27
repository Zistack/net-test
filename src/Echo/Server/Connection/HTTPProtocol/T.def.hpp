T::T
(
	const HTTP::Server::Config::T & config,
	const std::optional <HTTP::HostData::T> & host_data,
	const std::pair <std::tuple <>, std::tuple <const WebSocket::Config::T &>> &
		upgrade_arguments
)
:	HTTPProtocolInterface::T (config, host_data, upgrade_arguments)
{
}

T::T
(
	const HTTP::Server::Config::T & config,
	const std::optional <HTTP::HostData::T> & host_data,
	const std::pair <std::tuple <>, std::tuple <const WebSocket::Config::T &>> &
		upgrade_arguments
)
:	HTTPProtocolInterface::T (config, host_data, upgrade_arguments)
{
	if (host_data == std::nullopt)
	{
		fprintf (stderr, "Setting server host data to null\n");
	}
	else
	{
		fprintf (stderr, "Setting server host data to non-null\n");
	}
}

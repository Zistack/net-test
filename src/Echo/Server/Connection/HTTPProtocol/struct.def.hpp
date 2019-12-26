struct T : private HTTPProtocolInterface::T
{
	T
	(
		const HTTP::Server::Config::T & config,
		const std::optional <HTTP::HostData::T> & host_data,
		const std::pair
		<
			std::tuple <>,
			std::tuple <const WebSocket::Config::T &>
		> &
			upgrade_arguments
	);

	using HTTPProtocolInterface::T::prime;
	using HTTPProtocolInterface::T::run;
	using HTTPProtocolInterface::T::cancel;

	~T () = default;
};

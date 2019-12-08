struct T : private HTTPProtocolInterface::T
{
	T
	(
		const HTTP::Server::Config::T & config,
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

struct T : private FIFOProtocolInterface::T
{
	T (const Echo::Server::FIFOProtocol::Config::T & config);

	using FIFOProtocolInterface::T::prime;
	using FIFOProtocolInterface::T::run;
	using FIFOProtocolInterface::T::cancel;

	~T () = default;
};

struct T : private FIFOProtocolInterface::T
{
	T (Echo::Client::FIFOProtocol::T & echo_protocol);

	using FIFOProtocolInterface::T::prime;
	using FIFOProtocolInterface::T::run;
	using FIFOProtocolInterface::T::cancel;

	~T () = default;
};

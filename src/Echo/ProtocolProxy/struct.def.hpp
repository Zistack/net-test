struct T : private FIFOProtocolInterface::T
{
	using FIFOProtocolInterface::T::T;

	using FIFOProtocolInterface::T::prime;
	using FIFOProtocolInterface::T::run;
	using FIFOProtocolInterface::T::cancel;

	~T () = default;
};

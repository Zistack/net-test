struct T : private HTTPProtocolInterface::T
{
	using HTTPProtocolInterface::T::T;

	using HTTPProtocolInterface::T::prime;
	using HTTPProtocolInterface::T::run;
	using HTTPProtocolInterface::T::cancel;

	~T () = default;
};

struct T : private WebSocketProtocolInterface::T
{
	using WebSocketProtocolInterface::T::ResponseFactory;

	using WebSocketProtocolInterface::T::T;

	using WebSocketProtocolInterface::T::prime;
	using WebSocketProtocolInterface::T::run;
	using WebSocketProtocolInterface::T::cancel;

	~T () = default;
};

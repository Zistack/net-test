struct T : private WebSocketProtocolInterface::T
{
	using WebSocketProtocolInterface::T::ProtocolData;

	using WebSocketProtocolInterface::T::T;

	using WebSocketProtocolInterface::T::prime;
	using WebSocketProtocolInterface::T::run;
	using WebSocketProtocolInterface::T::cancel;

	~T () = default;

	using WebSocketProtocolInterface::T::createResponse;

	using WebSocketProtocolInterface::T::NAME;
};

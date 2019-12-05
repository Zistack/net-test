void
T::dispatch (WebSocket::Message::T && message)
{
	this -> webSocketProtocol () . send (std::move (message));
}

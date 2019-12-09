const WebSocket::Config::T &
T::webSocketConfig () const
{
	return this -> value <Spec::WEBSOCKET_CONFIG> ();
}

WebSocket::Config::T &
T::webSocketConfig ()
{
	return this -> value <Spec::WEBSOCKET_CONFIG> ();
}

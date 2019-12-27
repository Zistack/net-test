const Echo::Client::WebProtocol::Config::T &
T::echoConfig () const
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

Echo::Client::WebProtocol::Config::T &
T::echoConfig ()
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

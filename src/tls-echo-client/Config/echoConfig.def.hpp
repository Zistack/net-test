const Echo::Client::FIFOProtocol::Config::T &
T::echoConfig () const
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

Echo::Client::FIFOProtocol::Config::T &
T::echoConfig ()
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

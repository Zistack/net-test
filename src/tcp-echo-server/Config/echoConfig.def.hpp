const Echo::Server::FIFOProtocol::Config::T &
T::echoConfig () const
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

Echo::Server::FIFOProtocol::Config::T &
T::echoConfig ()
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

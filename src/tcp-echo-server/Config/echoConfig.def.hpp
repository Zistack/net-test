const Echo::Server::Protocol::Config::T &
T::echoConfig () const
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

Echo::Server::Protocol::Config::T &
T::echoConfig ()
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

const Echo::Client::Protocol::Config::T &
T::echoConfig () const
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

Echo::Client::Protocol::Config::T &
T::echoConfig ()
{
	return this -> value <Spec::ECHO_CONFIG> ();
}

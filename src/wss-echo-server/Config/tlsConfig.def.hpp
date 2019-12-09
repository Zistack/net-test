const TLS::Server::Config::T &
T::tlsConfig () const
{
	return this -> value <Spec::TLS_CONFIG> ();
}

TLS::Server::Config::T &
T::tlsConfig ()
{
	return this -> value <Spec::TLS_CONFIG> ();
}

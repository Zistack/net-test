const HTTP::Server::Config::T &
T::httpConfig () const
{
	return this -> value <Spec::HTTP_CONFIG> ();
}

HTTP::Server::Config::T &
T::httpConfig ()
{
	return this -> value <Spec::HTTP_CONFIG> ();
}

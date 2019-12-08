const HTTP::Client::Config::T &
T::httpConfig () const
{
	return this -> value <Spec::HTTP_CONFIG> ();
}

HTTP::Client::Config::T &
T::httpConfig ()
{
	return this -> value <Spec::HTTP_CONFIG> ();
}

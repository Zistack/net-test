T::T (const Server::Protocol::Config::T & config)
:	Base::T (config . inputTimeout (), config . outputTimeout ())
{
}

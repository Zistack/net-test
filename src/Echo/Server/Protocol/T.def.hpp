T::T (const Config::T & config)
:	Base::T (config . inputTimeout (), config . outputTimeout ())
{
}

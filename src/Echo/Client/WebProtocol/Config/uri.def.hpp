const URI::T &
T::uri () const
{
	return this -> value <Spec::URI> ();
}

URI::T &
T::uri ()
{
	return this -> value <Spec::URI> ();
}

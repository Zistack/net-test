const URI::T &
T::resource () const
{
	return this -> value <Spec::RESOURCE> ();
}

URI::T &
T::resource ()
{
	return this -> value <Spec::RESOURCE> ();
}

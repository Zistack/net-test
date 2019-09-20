int
main (int argc, char ** argv)
{
	Failure::ExceptionStore::T exception_store;

	exception_store . tryStore ([] () { throw Failure::Error::T ("Bad\n"); });

	return 0;
}

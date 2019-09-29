int
main (int argc, char ** argv)
{
	std::mutex output_mutex;
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::Aggregate::T nursery
		(
			exception_store,
			std::forward_as_tuple
			(
				nullptr,
				[&] ()
				{
					std::unique_lock output_lock (output_mutex);

					printf ("0\n");
				}
			),
			std::forward_as_tuple
			(
				nullptr,
				[&] ()
				{
					std::unique_lock output_lock (output_mutex);

					printf ("1\n");
				}
			),
			std::forward_as_tuple
			(
				nullptr,
				[&] ()
				{
					std::unique_lock output_lock (output_mutex);

					printf ("2\n");
				}
			)
		);
	}

	{
		Thread::Nursery::Aggregate::T nursery
		(
			exception_store,
			std::forward_as_tuple
			(
				nullptr,
				[] () { throw Failure::Error::T ("Bad\n"); }
			)
		);
	}

	exception_store . poll ();

	return 0;
}

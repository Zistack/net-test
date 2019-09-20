int
main (int argc, char ** argv)
{
	std::mutex output_mutex;

	Thread::Nursery::Aggregate::T nursery
	(
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

	return 0;
}

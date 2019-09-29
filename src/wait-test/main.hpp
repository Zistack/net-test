int
main (int argc, char ** argv)
{
	IO::CancelSignal::T cancel_signal;

	std::thread t
	(
		[&] ()
		{
			std::this_thread::sleep_for (std::chrono::seconds (1));

			cancel_signal . cancel ();
		}
	);

	IO::Util::wait (IO::FileDescriptor::Input::T (STDIN_FILENO), cancel_signal);

	t . join ();

	return 0;
}

int
main (int argc, char ** argv)
{
	IO::Util::setNonblocking (STDIN_FILENO);
	IO::Blocking::InputStream::T stdin
	(
		IO::FileDescriptor::Reciever::T (STDIN_FILENO)
	);

	IO::Util::setNonblocking (STDOUT_FILENO);
	IO::Blocking::OutputStream::T stdout
	(
		IO::FileDescriptor::Sender::T (STDOUT_FILENO)
	);

	// Get server configuration.

	std::string config_file_name = "tcp-echo-server.cfg";

	GetOpts::Spec::T getopts_spec
	(
		"[-c filename]",
		"A simple echo server over TCP.",
		{
			{
				'c',
				"config",
				[&] (char * filename)
				{
					config_file_name = std::string (filename);
				},
				"Specifies the location of the config file to be used.  The "
					"default value is '" + config_file_name + "'."
			},
			{
				'h',
				"help",
				[&] ()
				{
					getopts_spec . printHelp (stdout, argv [0], 80, 8, 0);

					exit (EXIT_SUCCESS);
				},
				"Prints this message and exits."
			}
		}
	);

	GetOpts::parse (argc, argv, getopts_spec, nullptr);

	IO::File::T config_file (config_file_name, "r");

	Config::T config (IO::Blocking::InputStream::T (config_file . reader ()));

	// Construct the echo server.

	Echo::Server::Protocol::T echo_protocol (config . echoConfig ());

	TCP::Server::Service::T tcp_server (echo_protocol, config . tcpConfig ());

	// Prime the echo server.

	tcp_server . prime ();

	// Run the echo server.

	Thread::Nursery::Aggregate::T nursery
	(
		std::forward_as_tuple (tcp_server, [&] () { tcp_server . run (); }),
		std::forward_as_tuple
		(
			stdin,
			[&] ()
			{
				try
				{
					while (true) stdin . get ();
				}
				catch (Failure::CancelException::T)
				{
					stdin . clear ();
				}
			}
		)
	);

	return 0;
}

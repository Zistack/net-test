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

	std::string config_file_name = "wss-echo-server.cfg";

	GetOpts::Spec::T getopts_spec
	(
		"[-c filename]",
		"A simple echo server over WSS.",
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
					getopts_spec . printHelp (stdout, argv [0], 90, 9, 0);

					stdout . flush ();

					exit (EXIT_SUCCESS);
				},
				"Prints this message and exits."
			},
			{
				"config-help",
				[&] ()
				{
					Config::T::printHelp (stdout, 80, 8, 0);

					stdout . flush ();

					exit (EXIT_SUCCESS);
				},
				"Prints documentation for the configuration file and exits."
			}
		}
	);

	GetOpts::parse (argc, argv, getopts_spec, nullptr);

	// There's an IO::Util::parseFile that might be more appropriate here.

	IO::File::T config_file (config_file_name, "r");

	Config::T config (IO::Blocking::InputStream::T (config_file . reader ()));

	// Create the echo server.

	Echo::Server::WebProtocol::T echo_protocol
	(
		config . httpConfig (),
		std::make_pair
		(
			std::make_tuple (),
			std::make_tuple (config . webSocketConfig ())
		)
	);

	TLS::Server::Service::T tls_server (echo_protocol, config . tlsConfig ());

	// Prime the echo server.

	tls_server . prime ();

	// Run the echo server.

	Thread::Nursery::Aggregate::T nursery
	(
		std::forward_as_tuple (tls_server, [&] () { tls_server . run (); }),
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
				catch (Failure::EndOfResource::T)
				{
					tls_server . cancel ();
				}
			}
		)
	);

	return 0;
}

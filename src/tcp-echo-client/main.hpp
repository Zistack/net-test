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

	// Get client configuration.

	std::string config_file_name = "tcp-echo-client.cfg";

	GetOpts::Spec::T getopts_spec
	(
		"[-c filename]",
		"A simple echo client over TCP.",
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

	// Construct the echo client.

	Echo::Client::FIFOProtocol::T echo_protocol (config . echoConfig ());

	TCP::Client::Service::T tcp_client (echo_protocol, config . tcpConfig ());

	Echo::ProtocolProxy::T echo_proxy (echo_protocol);

	// Prime the echo client.

	tcp_client . prime ();
	echo_proxy . prime ();

	// Run the echo client.

	Thread::Nursery::Aggregate::T nursery
	(
		std::forward_as_tuple
		(
			tcp_client,
			[&] ()
			{
				tcp_client . run ();
			}
		),
		std::forward_as_tuple
		(
			echo_proxy,
			[&] ()
			{
				echo_proxy . run (stdin, stdout);
				tcp_client . cancel ();
			}
		)
	);

	return 0;
}

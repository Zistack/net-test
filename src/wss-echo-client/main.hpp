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

	std::string config_file_name = "wss-echo-client.cfg";

	GetOpts::Spec::T getopts_spec
	(
		"[-c filename]",
		"A simple echo client over WSS.",
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
					{
						Scope::T output_scope (stdout);

						getopts_spec . printHelp (stdout, argv [0], 80, 8, 0);
					}

					exit (EXIT_SUCCESS);
				},
				"Prints this message and exits."
			},
			{
				"config-help",
				[&] ()
				{
					{
						Scope::T output_scope (stdout);

						Config::T::printHelp (stdout, 80, 8, 0);
					}

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

	// Create the echo client.

	Echo::Client::WebProtocol::T echo_protocol
	(
		config . tlsConfig () . serverName (),
		config . echoConfig (),
		stdin,
		stdout
	);

	TLS::Client::Service::T tls_client (echo_protocol, config . tlsConfig ());

	// Prime the echo client.

	tls_client . prime ();

	// Run the echo client.

	tls_client . run ();

	return 0;
}

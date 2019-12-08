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

	Echo::Server::FIFOProtocol::Config::T echo_config;

	Echo::Server::Connection::FIFOProtocol::T echo_protocol (echo_config);

	echo_protocol . prime ();

	echo_protocol . run (stdin, stdout);

	return 0;
}

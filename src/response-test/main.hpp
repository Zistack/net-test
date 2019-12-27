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

	HTTP::Input::CancellableSlot::T <decltype (stdin) &> input_slot;

	HTTP::Response::T response (stdin, input_slot, 4096);

	HTTP::Output::CancellableSlot::T <decltype (stdout) &> output_slot;

	response . writeTo
	(
		stdout,
		output_slot,
		HTTP::TransferEncoding::Config::T ()
	);

	stdout . flush ();

	return 0;
}

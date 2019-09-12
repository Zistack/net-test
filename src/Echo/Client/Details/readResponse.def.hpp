template <typename InputStream>
std::string
T::readResponse (InputStream && input_stream)
{
	std::string response;

	while (! IO::Util::test (std::forward <InputStream> (input_stream), '\n'))
	{
		response . push_back (input_stream . get ());
	}
	input_stream . get ();

	return response;
}

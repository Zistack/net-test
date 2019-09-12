template <typename InputStream>
std::string
T::readRequest (InputStream && input_stream)
{
	std::string request;

	while (! IO::Util::test (std::forward <InputStream> (input_stream), '\n'))
	{
		request . push_back (input_stream . get ());
	}
	input_stream . get ();

	return request;
}

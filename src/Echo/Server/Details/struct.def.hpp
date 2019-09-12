struct T
{
	template <typename InputStream>
	std::string
	readRequest (InputStream && input_stream);

	std::string
	map (const std::string & request);

	template <typename OutputStream>
	void
	writeResponse (const std::string & response, OutputStream && output_stream);
};

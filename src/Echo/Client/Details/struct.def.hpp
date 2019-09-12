struct T
{
	template <typename OutputStream>
	void
	writeRequest (const std::string & request, OutputStream && output_stream);

	template <typename InputStream>
	std::string
	readResponse (InputStream && input_stream);
};

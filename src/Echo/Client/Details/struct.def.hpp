struct T
{
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout
	);

	template <typename OutputStream>
	void
	writeRequest (const std::string & request, OutputStream && output_stream);

	template <typename InputStream>
	std::string
	readResponse (InputStream && input_stream);

	~T () = default;

private:

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
};

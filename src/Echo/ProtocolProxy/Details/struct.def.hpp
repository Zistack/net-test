struct T
{
	T (Echo::Client::Protocol::T & echo_protocol);

	template <typename InputStream>
	std::string
	readRequest (InputStream && input_stream);

	std::string
	map (const std::string & request);

	template <typename OutputStream>
	void
	writeResponse (const std::string & response, OutputStream && output_stream);

	~T () = default;

private:

	Echo::Client::Protocol::T & m_echo_protocol;
};

struct T
:	::FIFOProtocol::Server::Connection::Protocol::T
	<
		T,
		std::string,
		std::string
	>
{
	template <typename InputStream>
	std::string
	readRequest (InputStream && input_stream);

	std::string
	map (const std::string & request);

	template <typename OutputStream>
	void
	writeResponse (const std::string & response, OutputStream && output_stream);

protected:

	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout
	);

	~T () = default;

private:

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
};

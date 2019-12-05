struct T
:	FIFOProtocol::Server::Connection::Protocol::T <T, std::string, std::string>
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

	T (Echo::Client::FIFOProtocol::T & echo_protocol);

	~T () = default;

private:

	Echo::Client::FIFOProtocol::T & m_echo_protocol;
};

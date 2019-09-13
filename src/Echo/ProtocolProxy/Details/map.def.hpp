std::string
T::map (const std::string & request)
{
	return this -> m_echo_protocol . makeRequest (request);
}

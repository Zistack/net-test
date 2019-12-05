T::T (const Config::T & config)
:	::FIFOProtocol::Client::Protocol::T <T, std::string, std::string>
	(
		config . roundTripTimeout ()
	),
	m_input_timeout (config . inputTimeout ()),
	m_output_timeout (config . outputTimeout ())
{
}

T::T (const Echo::Server::FIFOProtocol::Config::T & config)
:	FIFOProtocolInterface::T
	(
		config . inputTimeout (),
		config . outputTimeout ()
	)
{
}

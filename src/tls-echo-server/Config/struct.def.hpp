struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TLS::Server::Config::T &
	tlsConfig () const;

	TLS::Server::Config::T &
	tlsConfig ();

	const Echo::Server::FIFOProtocol::Config::T &
	echoConfig () const;

	Echo::Server::FIFOProtocol::Config::T &
	echoConfig ();
};

struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TLS::Client::Config::T &
	tlsConfig () const;

	TLS::Client::Config::T &
	tlsConfig ();

	const Echo::Client::FIFOProtocol::Config::T &
	echoConfig () const;

	Echo::Client::FIFOProtocol::Config::T &
	echoConfig ();
};

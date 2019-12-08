struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const Echo::Server::FIFOProtocol::Config::T &
	echoConfig () const;

	Echo::Server::FIFOProtocol::Config::T &
	echoConfig ();
};

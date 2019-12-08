struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const Echo::Client::FIFOProtocol::Config::T &
	echoConfig () const;

	Echo::Client::FIFOProtocol::Config::T &
	echoConfig ();
};

struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const Echo::Client::WebProtocol::Config::T &
	echoConfig () const;

	Echo::Client::WebProtocol::Config::T &
	echoConfig ();
};

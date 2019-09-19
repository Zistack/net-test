struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const Echo::Client::Protocol::Config::T &
	echoConfig () const;

	Echo::Client::Protocol::Config::T &
	echoConfig ();
};

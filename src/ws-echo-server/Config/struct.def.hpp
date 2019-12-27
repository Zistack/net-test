struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const HTTP::Server::Config::T &
	httpConfig () const;

	HTTP::Server::Config::T &
	httpConfig ();

	const WebSocket::Config::T &
	webSocketConfig () const;

	WebSocket::Config::T &
	webSocketConfig ();
};

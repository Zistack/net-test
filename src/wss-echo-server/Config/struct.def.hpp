struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TLS::Server::Config::T &
	tlsConfig () const;

	TLS::Server::Config::T &
	tlsConfig ();

	const HTTP::Server::Config::T &
	httpConfig () const;

	HTTP::Server::Config::T &
	httpConfig ();

	const WebSocket::Config::T &
	webSocketConfig () const;

	WebSocket::Config::T &
	webSocketConfig ();
};

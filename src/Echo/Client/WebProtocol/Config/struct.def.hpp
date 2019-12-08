struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const URI::T &
	uri () const;

	URI::T &
	uri ();

	const HTTP::Client::Config::T &
	httpConfig () const;

	HTTP::Client::Config::T &
	httpConfig ();

	const WebSocket::Config::T &
	webSocketConfig () const;

	WebSocket::Config::T &
	webSocketConfig ();
};

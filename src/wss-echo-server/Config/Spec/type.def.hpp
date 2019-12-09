template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		TLS::Server::Config::T,
		false,
		TLS_CONFIG,
		TLS_CONFIG_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		HTTP::Server::Config::T,
		false,
		HTTP_CONFIG,
		HTTP_CONFIG_DESCRIPTION,
		HTTP_CONFIG_DEFAULT
	>,
	GetConfig::Member::T
	<
		WebSocket::Config::T,
		false,
		WEBSOCKET_CONFIG,
		WEBSOCKET_CONFIG_DESCRIPTION,
		WEBSOCKET_CONFIG_DEFAULT
	>
>;

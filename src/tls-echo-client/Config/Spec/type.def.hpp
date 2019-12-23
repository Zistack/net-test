template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		TLS::Client::Config::T,
		false,
		TLS_CONFIG,
		TLS_CONFIG_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		Echo::Client::FIFOProtocol::Config::T,
		false,
		ECHO_CONFIG,
		ECHO_CONFIG_DESCRIPTION,
		ECHO_CONFIG_DEFAULT
	>
>;

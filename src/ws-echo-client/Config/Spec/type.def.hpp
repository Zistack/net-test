template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		TCP::Config::T,
		false,
		TCP_CONFIG,
		TCP_CONFIG_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		Echo::Client::WebProtocol::Config::T,
		false,
		ECHO_CONFIG,
		ECHO_CONFIG_DESCRIPTION,
		ECHO_CONFIG_DEFAULT
	>
>;

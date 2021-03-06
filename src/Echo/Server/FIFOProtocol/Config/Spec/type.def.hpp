template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		GetConfig::Duration::T,
		false,
		INPUT_TIMEOUT,
		INPUT_TIMEOUT_DESCRIPTION,
		INPUT_TIMEOUT_DEFAULT
	>,
	GetConfig::Member::T
	<
		GetConfig::Duration::T,
		false,
		OUTPUT_TIMEOUT,
		OUTPUT_TIMEOUT_DESCRIPTION,
		OUTPUT_TIMEOUT_DEFAULT
	>
>;

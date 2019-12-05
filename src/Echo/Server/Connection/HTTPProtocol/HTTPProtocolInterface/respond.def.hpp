HTTP::Response::T
T::respond (const HTTP::Request::T & request)
{
	// Any request that makes it here is a request we don't want to handle.

	return HTTP::Response::T
	(
		"1.1",
		426,
		"Upgrade Required",
		{std::make_pair ("Sec-WebSocket-Version", "13")},
		std::nullopt
	);
}

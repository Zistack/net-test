template <typename InterfaceInputStream, typename InterfaceOutputStream>
template <typename InputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::event
(
	InputStream && input_stream
)
{
	WebSocket::Message::T message (WebSocket::Type::TEXT);

	message . withWriter
	(
		[&] (auto && output_stream)
		{
			while
			(
				! IO::Util::test
				(
					std::forward <InputStream> (input_stream),
					'\n'
				)
			)
			{
				output_stream . put (input_stream . get ());
			}
			input_stream . get ();
		}
	);

	this -> websocketProtocol () . send (std::move (message));
}

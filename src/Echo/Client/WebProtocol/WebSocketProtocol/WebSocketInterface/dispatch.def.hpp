template <typename OutputStream>
void
T <OutputStream>::dispatch (WebSocket::Message::T && message)
{
	message . withReader
	(
		[&] (auto && input_stream)
		{
			while (! input_stream . eof ())
			{
				this -> m_output_stream . put (input_stream . get ());
			}
			this -> m_output_stream . put ('\n');
		}
	);

	this -> m_output_stream . flush ();
}

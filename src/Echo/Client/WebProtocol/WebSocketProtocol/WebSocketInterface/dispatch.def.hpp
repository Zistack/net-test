template <typename OutputStream>
void
T <OutputStream>::dispatch (WebSocket::Message::T && message)
{
	Scope::T output_scope (this -> m_output_stream);

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
}

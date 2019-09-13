template <typename OutputStream>
void
T::writeResponse (const std::string & response, OutputStream && output_stream)
{
	try
	{
		{
			Thread::Timer::T output_timer
			(
				this -> m_output_timeout,
				& OutputStream::cancel,
				& output_stream
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

				output_stream . print (response + "\n");
			}
			else
			{
				output_stream . print (response + "\n");
			}
		}
		if constexpr (IO::TypeTraits::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing response timed out");
	}
}

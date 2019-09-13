template <typename OutputStream>
void
T::writeRequest (const std::string & request, OutputStream && output_stream)
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

				output_stream . print (request + "\n");
			}
			else
			{
				output_stream . print (request + "\n");
			}
		}
		if constexpr (IO::TypeTraits::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing request timed out");
	}
}

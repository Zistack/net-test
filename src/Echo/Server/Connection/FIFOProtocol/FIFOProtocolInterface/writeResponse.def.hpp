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
				[&] () { output_stream . cancel (); }
			);

			output_stream . print (response + "\n");

			if constexpr (IO::IsBuffered::T <OutputStream>::value)
			{
				output_stream . flush ();
			}
		}
		if constexpr (IO::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing response timed out");
	}
}

template <typename InputStream>
std::string
T::readResponse (InputStream && input_stream)
{
	try
	{
		std::string response;

		{
			Thread::Timer::T input_timer
			(
				this -> m_input_timeout,
				[&] () { input_stream . cancel (); }
			);

			while
			(
				! IO::Util::test
				(
					std::forward <InputStream> (input_stream),
					'\n'
				)
			)
			{
				response . push_back (input_stream . get ());
			}
			input_stream . get ();
		}
		if constexpr (IO::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}

		return response;
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading response timed out\n");
	}
}

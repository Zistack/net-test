template <typename InputStream>
std::string
T::readRequest (InputStream && input_stream)
{
	try
	{
		std::string request;

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
				request . push_back (input_stream . get ());
			}
			input_stream . get ();
		}
		if constexpr (IO::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}

		return request;
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading request timed out\n");
	}
}

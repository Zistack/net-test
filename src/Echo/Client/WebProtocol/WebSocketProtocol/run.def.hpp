template <typename InterfaceInputStream, typename InterfaceOutputStream>
template <typename InputStream, typename OutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::run
(
	InputStream && input_stream,
	OutputStream && output_stream
)
{
	Scope::T shutdown_scope (std::move (this -> m_shutdown_scope));

	{
		Thread::Nursery::Aggregate::T
		(
			std::forward_as_tuple
			(
				this -> webSocketProtocol (),
				[&] ()
				{
					this -> webSocketProtocol () . run
					(
						std::forward <InputStream> (input_stream),
						std::forward <OutputStream> (output_stream)
					);
				}
			),
			std::forward_as_tuple
			(
				this -> m_shutdown_signal,
				[&] ()
				{
					Failure::ExceptionStore::T exception_store;

					IO::Util::eventLoop
					(
						exception_store,
						std::forward <InterfaceInputStream>
						(
							this -> m_interface_input_stream
						),
						this -> m_shutdown_signal,
						[&] ()
						{
							this -> event ();
						}
					);

					exception_store . poll ();
				}
			)
		);
	}
}

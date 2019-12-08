template <typename InterfaceInputStream, typename InterfaceOutputStream>
struct T : WebSocketInterface::T <InterfaceOutputStream>
{
	using ProtocolData =
		typename WebSocketInterface::T <InterfaceOutputStream>::ProtocolData;

	T
	(
		const T::ProtocolData & protocol_data,
		const HTTP::Response::T & response,
		const WebSocket::Config::T & websocket_config,
		InterfaceInputStream interface_input_stream,
		InterfaceOutputStream interface_output_stream
	);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;

private:

	void
	event ();

	// Given members

	InterfaceInputStream m_interface_input_stream;

	// Internal members

	ShutdownSignal::T m_shutdown_signal;

	// Transient members

	Scope::T <ShutdownSignal::T> m_shutdown_scope;
};

template <typename InterfaceInputStream, typename InterfaceOutputStream>
T
(
	const typename T <InterfaceInputStream, InterfaceOutputStream>::
		ProtocolData &
			protocol_data,
	const HTTP::Response::T & response,
	const WebSocket::Config::T & websocket_config,
	InterfaceInputStream && interface_input_stream,
	InterfaceOutputStream && interface_output_stream
) ->
	T <InterfaceInputStream, InterfaceOutputStream>;

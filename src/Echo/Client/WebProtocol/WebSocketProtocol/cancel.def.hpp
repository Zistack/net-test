template <typename InterfaceInputStream, typename InterfaceOutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::cancel ()
{
	this -> webSocketProtocol () . cancel ();
	this -> m_shutdown_signal . cancel ();
}

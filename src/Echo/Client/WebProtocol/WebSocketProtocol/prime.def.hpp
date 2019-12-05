template <typename InterfaceInputStream, typename InterfaceOutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::prime ()
{
	this -> webSocketProtocol () . prime ();
	this -> m_shutdown_scope = Scope::T (this -> m_shutdown_signal);
}

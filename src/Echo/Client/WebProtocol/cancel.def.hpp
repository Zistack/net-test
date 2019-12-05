template <typename InterfaceInputStream, typename InterfaceOutputStream>
void
T <InterfaceInputStream, InterfaceOutputStream>::cancel ()
{
	this -> m_cancellable . cancel ();
}

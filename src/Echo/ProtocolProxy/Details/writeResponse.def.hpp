template <typename OutputStream>
void
T::writeResponse (const std::string & response, OutputStream && output_stream)
{
	Scope::T output_scope (output_stream);

	output_stream . print (response + "\n");
}

template <typename OutputStream>
void
T::writeResponse (const std::string & response, OutputStream && output_stream)
{
	output_stream . print (response + "\n");
}

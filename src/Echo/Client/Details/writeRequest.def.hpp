template <typename OutputStream>
void
T::writeRequest (const std::string & request, OutputStream && output_stream)
{
	output_stream . print (request + "\n");
}

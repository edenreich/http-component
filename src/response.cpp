#include "http/response.h"
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


Response::Response()
{
    //
}

/**
 * Retrieve the stream body.
 * 
 * @return const Interfaces::StreamInterface &
 */
const Interfaces::StreamInterface & Response::getBody() const
{
    throw NotImplementedException();
}

/**
 * Retrieve the status code.
 * 
 * @return int
 */
int Response::getStatusCode() const
{
    throw NotImplementedException();
}
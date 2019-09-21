#include "response.h"
#include "not_implemented_exception.h"

using namespace Http;


Response::Response()
{
    //
}

/**
 * Retrieve the stream body.
 * 
 * @return Interfaces::StreamInterface &
 */
Interfaces::StreamInterface & Response::getBody() const
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
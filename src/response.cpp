#include "http/response.h"
#include "http/exceptions/not_implemented_exception.h"

#include "http/socket_stream.h"

using namespace Http;


/**
 * Construct a response.
 */
Response::Response() : m_stream(nullptr)
{
    //
}

/**
 * Construct a response.
 * 
 * - Initialize a stream
 * 
 * @param Http::Interfaces::SocketStreamInterface * stream
 */
Response::Response(Interfaces::SocketStreamInterface * stream) : m_stream(stream)
{
    //
}

/**
 * Destructor a response.
 */
Response::~Response()
{
    delete m_stream;
}

/**
 * Retrieve the body stream.
 * 
 * @return Http::Interfaces::SocketStreamInterface *
 */
Interfaces::SocketStreamInterface * Response::getBody()
{
    return m_stream;
}

/**
 * Retrieve the status code.
 * 
 * @return Http::StatusCode
 */
StatusCode Response::getStatusCode() const
{
    throw Exceptions::NotImplementedException();
}
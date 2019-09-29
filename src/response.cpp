#include "http/response.h"
#include "http/exceptions/not_implemented_exception.h"

#include "http/stream.h"

using namespace Http;


/**
 * Construct a response.
 */
Response::Response() : m_stream(new Stream)
{
    //
}

/**
 * Construct a response.
 * 
 * - Initialize a stream
 * 
 * @param Http::Interfaces::StreamInterface * stream
 */
Response::Response(Interfaces::StreamInterface * stream) : m_stream(stream)
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
 * @return Http::Interfaces::StreamInterface *
 */
Interfaces::StreamInterface * Response::getBody()
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
#include "http/response.h"
#include "http/exceptions/not_implemented_exception.h"

#include "http/socket_stream.h"

#include <regex>

using namespace Http;


/**
 * Construct a response.
 */
Response::Response() : m_stream(new SocketStream), m_statusCode(StatusCode::NOT_FOUND)
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
Response::Response(Interfaces::SocketStreamInterface * stream) : m_stream(stream), m_statusCode(StatusCode::NOT_FOUND)
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
StatusCode Response::getStatusCode()
{
    std::regex pattern("^HTTP/\\d\\.\\d\\s(\\d{3})\\s.+$");
    std::smatch matches;
    const std::string & content = m_stream->getContents();

    if (std::regex_match(content, matches, pattern)) {
        const std::string & statusCodeStr = matches[1].str();
        
        unsigned int statusCode;
        std::stringstream ss;

        ss << statusCodeStr;
        ss >> statusCode;

        m_statusCode = static_cast<StatusCode>(statusCode);
    }

    return m_statusCode;
}
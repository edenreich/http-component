#include "http/response.h"
#include "http/exceptions/not_implemented_exception.h"

#include "http/client_socket.h"

#include <regex>

using namespace Http;


/**
 * Construct a response.
 */
Response::Response() : m_socket(new ClientSocket), m_statusCode(StatusCode::NOT_FOUND)
{
    //
}

/**
 * Construct a response.
 * 
 * - Initialize a socket
 * 
 * @param Http::Interfaces::ClientSocketInterface * socket
 */
Response::Response(Interfaces::ClientSocketInterface * socket) : m_socket(socket), m_statusCode(StatusCode::NOT_FOUND)
{
    //
}

/**
 * Destructor a response.
 */
Response::~Response()
{
    delete m_socket;
}

/**
 * Retrieve the body stream.
 * 
 * @return Http::Interfaces::ClientSocketInterface *
 */
Interfaces::ClientSocketInterface * Response::getBody() const
{
    return m_socket;
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
    const std::string & content = m_socket->getContents();

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
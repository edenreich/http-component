#include "http/response.h"

#include "http/client_socket.h"

#include <regex>

using namespace Http;


/**
 * Construct a response.
 */
Response::Response() : m_message(nullptr), m_statusCode(StatusCode::NOT_FOUND)
{
    //
}

/**
 * Construct a response.
 * 
 * - Initialize a message
 * 
 * @param Http::Interfaces::MessageInterface * message
 */
Response::Response(Interfaces::MessageInterface * message) : m_message(message), m_statusCode(StatusCode::NOT_FOUND)
{
    //
}

/**
 * Destructor a response.
 */
Response::~Response()
{
    delete m_message;
}

/**
 * Retrieve the body stream.
 * 
 * @return const std::stringstream const
 */
const std::stringstream & Response::getBody() const
{
    return m_message->getBody();
}

/**
 * Retrieve the message.
 * 
 * @return Http::Interfaces::MessageInterface *
 */
Interfaces::MessageInterface * Response::getMessage() const
{
    return m_message;
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
    std::string protocolLine = m_message->getProtocolLine();

    if (std::regex_match(protocolLine, matches, pattern)) {
        const std::string & statusCodeStr = matches[1].str();
        
        unsigned int statusCode;
        std::stringstream ss;

        ss << statusCodeStr;
        ss >> statusCode;

        m_statusCode = static_cast<StatusCode>(statusCode);
    }

    return m_statusCode;
}
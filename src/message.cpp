#include "http/message.h"

using namespace Http;


/**
 * Construct a message.
 * 
 * @param const std::string & content
 */
Message::Message(const std::string & content) : m_content(content)
{
    // @todo parse the content of the message.
}

/**
 * Construct a message.
 * 
 * @param const std::stringstream & content
 */
Message::Message(const std::stringstream & content) : m_content(content.str())
{

    // @todo pre parse the message content of the message.
}

/**
 * Destruct the message.
 */
Message::~Message()
{

}

/**
 * Get the first line of the message.
 * 
 * @return std::string
 */
std::string Message::getProtocolLine() const
{
    std::string firstLine;

    return firstLine;
}

/**
 * Retrieve the message headers.
 * 
 * @return Http::Headers
 */
Headers Message::getHeaders() const
{
    Headers headers;

    return headers;
}

/**
 * Retrieve the body stream.
 * 
 * @return std::stringstream
 */
std::stringstream Message::getBody() const
{
    std::stringstream ss;

    return ss;
}
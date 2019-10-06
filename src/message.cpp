#include "http/message.h"

using namespace Http;

#include "http/exceptions/invalid_message_exception.h"


/**
 * Construct a message.
 * 
 * @param const std::string & content
 */
Message::Message(const std::string & content) : m_content(content)
{
    if (content.empty()) {
        throw Exceptions::InvalidMessageException("Content of the message could not be empty!");
    }

    std::string trimmedContent = leftTrim(content);

    m_content << trimmedContent;

    std::getline(m_content, m_protocolLine);
    std::string trimmedLine = rightTrim(m_protocolLine);
    
    m_protocolLine = trimmedLine; 

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
    return m_protocolLine;
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

/**
 * Trim the spaces from the begin 
 * and the end of the given string.
 * 
 * @param const std::string &
 * @return std::string
 */
std::string Message::leftTrim(std::string content)
{
    for (const char & letter : content) {
        if (letter != 10 && letter != 32 && letter != 79 && letter != 84) {
            break;
        }

        content.erase(0, 1);
    }

    return content;
}

/**
 * Trim the spaces and linebreaks
 * from the end of the given content.
 * 
 * @param std::string
 * @return std::string
 */
std::string Message::rightTrim(std::string content)
{
    for (int i = content.size() - 1; i >= 0; i--) {
        if (content[i] != 110 && content[i] != 92 && content[i] != 114) {
            break;
        }

        content.erase(i, 1);
    }

    return content;
}
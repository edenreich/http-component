#include "http/message.h"

#include "http/exceptions/invalid_message_exception.h"

using namespace Http;

#include <regex>
#include <algorithm>


/**
 * Construct a message.
 * 
 * @param const std::string & content
 */
Message::Message(const std::string & content)
{
    if (content.empty()) {
        throw Exceptions::InvalidMessageException("Content of the message could not be empty!");
    }

    parse(content);
}

/**
 * Construct a message.
 * 
 * @param const std::stringstream & content
 */
Message::Message(const std::stringstream & content)
{
    if (content.str().empty()) {
        throw Exceptions::InvalidMessageException("Content of the message could not be empty!");
    }

    parse(content.str());
}

/**
 * Destruct the message.
 */
Message::~Message()
{
    m_content.clear();
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
    return m_headers;
}

/**
 * Retrieve the body stream.
 * 
 * @return std::stringstream
 */
const std::stringstream & Message::getBody() const
{
    return m_body;
}

/**
 * Retrieve the raw message
 * with the protocol line,
 * headers and body.
 * 
 * @return std::stringstream
 */
const std::stringstream & Message::getRaw() const
{
    return m_content;
}

/**
 * Parse the message content.
 * 
 * @param const std::string & content
 * @return void
 */
void Message::parse(const std::string & content)
{
    // Parse protocol line.
    std::string contentCopy = content;
    trim(contentCopy);
    m_content << contentCopy;

    std::getline(m_content, m_protocolLine);
    trim(m_protocolLine);

    // Parse Headers
    std::string line;
    while (std::getline(m_content, line))
    {
        trim(line, "\r\n");

        if (line.empty()) {
            break;
        }

        std::regex pattern(R"(^(([a-zA-Z-]+): (.*))?)", std::regex::extended);
        std::smatch matches;

        if (std::regex_match(line, matches, pattern)) {
            std::string key = matches[2].str();
            std::string value = matches[3].str();

            m_headers[key] = value;
            continue;
        }

        break;
    }

    // Parse Body
    std::string rest = m_content.str().substr(m_content.tellg());
    trim(rest);
    m_body << rest;
}

/**
 * Trim content from right and left.
 * 
 * @param std::string & content
 * @param const std::string & delimiters
 * @return void
 */
void Message::trim(std::string & content, const std::string & delimiters)
{
    leftTrim(content, delimiters);
    rightTrim(content, delimiters);
}

/**
 * Trim the spaces from the begin 
 * and the end of the given string.
 * 
 * @param std::string & content
 * @param const std::string & delimiters
 * @return void
 */
void Message::leftTrim(std::string & content, const std::string & delimiters)
{
    content.erase(0, content.find_first_not_of(delimiters));
}

/**
 * Trim the spaces and linebreaks
 * from the end of the given content.
 * 
 * @param std::string & content
 * @param const std::string & delimiters
 * @return void
 */
void Message::rightTrim(std::string & content, const std::string & delimiters)
{
    content.erase(content.find_last_not_of(delimiters) + 1);
}

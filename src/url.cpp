#include "http/url.h"
#include <algorithm>
#include <regex>
#include <iostream>
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


Url::Url(const std::string & url)
{
    parse(url);
}

/**
 * Retrieve the url.
 * 
 * @return std::string
 */
std::string Url::getUrl() const
{
    return m_url;
}

/**
 * Retrieve the encoded url.
 * 
 * @return std::string
 */
std::string Url::getEncodedUrl() const
{
    throw NotImplementedException();
}

/**
 * Retrieve the protocol.
 * 
 * @return std::string
 */
std::string Url::getProtocol() const
{
    return m_protocol;
}

/**
 * Retrieve the host.
 * 
 * @return std::string
 */
std::string Url::getHost() const
{
    return m_host;
}

/**
 * Retrieve the path.
 * 
 * @return std::string
 */
std::string Url::getPath() const
{
    return m_path;
}

/**
 * Parse a url and return it.
 * 
 * @param std::string & url
 * @return void
 */
void Url::parse(const std::string & url)
{
    std::regex pattern(R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)", std::regex::extended);
    std::smatch matches;

    if (std::regex_match(url, matches, pattern)) {
        m_url = matches[0];
        m_protocol = matches[2];
        m_host = matches[4];
        m_path = matches[5];
        m_query = matches[7];
    } else {
        std::cerr << "Malformed url." << std::endl;
    }
}
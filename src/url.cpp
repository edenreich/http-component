#include "http/url.h"
#include <algorithm>
#include <regex>

using namespace Http;


Url::Url(const std::string & url): m_url(url)
{
    parse(url);
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
 * Parse a url and return it.
 * 
 * @param std::string & url
 * @return void
 */
void Url::parse(std::string & url)
{
    // Parse protocol
    const std::regex pattern("^[^:]+(?=://)");
    std::smatch match;
    std::string encodedUrl = "";

    if (std::regex_search(url, match, pattern) && match.size() > 1) {
        std::string protocol = match.str(1);
        m_protocol = protocol;
    }
}
#include "http/url.h"
#include <algorithm>
#include <regex>
#include <map>
#include "http/exceptions/invalid_url_exception.h"

using namespace Http;


/**
 * Initialize a url string.
 * 
 * @param const std::string & url 
 */
Url::Url(const std::string & url)
{
    parse(url);
}

/**
 * Virtual Destructor.
 */
Url::~Url()
{

}

/**
 * Retrieve the url.
 * 
 * @return std::string
 */
std::string Url::get() const
{
    return m_url;
}

/**
 * Retrieve the encoded url.
 * 
 * @return std::string
 */
std::string Url::getEncoded() const
{
    std::map<const char, const std::string> signs = {
        {'%', "%25"},
        {'!', "%21"},
        {'#', "%23"},
        {'$', "%24"},
        {'&', "%26"},
        {'\'', "%27"},
        {'(', "%28"},
        {')', "%29"},
        {'*', "%2A"},
        {',', "%2C"},
        {'/', "%2F"},
        {':', "%3A"},
        {';', "%2B"},
        {'=', "%3D"},
        {'?', "%3F"},
        {'@', "%40"},
        {'[', "%5B"},
        {']', "%5D"},
        {' ', "+"},
    };

    std::string url;
    for (const char& c : m_url)
    {
        if (signs.find(c) == signs.end()) {
            url += c;
        } else {
            url += signs[c];
        }
    }

    return url;
}

/**
 * Retrieve the decoded url.
 * 
 * @return std::string
 */
std::string Url::getDecoded() const
{
    std::map<const std::string, const char> signs = {
        {"%25", '%'},
        {"%21", '!'},
        {"%23", '#'},
        {"%24", '$'},
        {"%26", '&'},
        {"%27", '\''},
        {"%28", '('},
        {"%29", ')'},
        {"%2A", '*'},
        {"%2C", ','},
        {"%2F", '/'},
        {"%3A", ':'},
        {"%2B", ';'},
        {"%3D", '='},
        {"%3F", '?'},
        {"%40", '@'},
        {"%5B", '['},
        {"%5D", ']'},
        {"+", ' '},
    };

    std::string url;
    for (auto it = m_url.begin(); it != m_url.end(); ++it)
    {
        if (*it != '%' && *it != '+') {
            url += *it;
            continue;
        }

        if (*it == '+') {
            url += ' ';
            continue;
        }

        if (*it == '%') {
            std::string sign;
            for (unsigned int i = 0; i < 2; i++) {
                sign += *it;
                ++it;
            }
            sign += *it;
            url += signs[sign];
        }
    }

    return url;
}

/**
 * Retrieve the scheme.
 * 
 * @return std::string
 */
std::string Url::getScheme() const
{
    return m_scheme;
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
        m_scheme = matches[2];
        m_host = matches[4];
        m_path = matches[5];
        m_query = matches[7];
    } else {
        throw InvalidUrlException();
    }
}
#include "http/request.h"
#include <string>
#include <sstream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

#include "http/exceptions/bad_connection_exception.h"
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


/**
 * Construct a request.
 *  
 * - initialize a response
 * 
 * @param const Interfaces::ResponseInterface & response
 */
Request::Request(const Interfaces::ResponseInterface & response) : m_response(response)
{
    //
}

/**
 * Send a get request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return const Interfaces::ResponseInterface &
 */
const Interfaces::ResponseInterface & Request::get(const Interfaces::UrlInterface & url) const
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) 
    {
        throw BadConnectionException();
    }

    int port = 80;
    if (!url.getPort().empty()) 
    {
        std::stringstream ss;
        ss << url.getPort();
        ss >> port;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, url.get().c_str(), &hint.sin_addr);

    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));

    return m_response;
}

/**
 * Send a post request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return const Interfaces::ResponseInterface &
 */
const Interfaces::ResponseInterface & Request::post(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a put request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return const Interfaces::ResponseInterface &
 */
const Interfaces::ResponseInterface & Request::put(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a patch request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return const Interfaces::ResponseInterface &
 */
const Interfaces::ResponseInterface & Request::patch(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a delete request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return const Interfaces::ResponseInterface &
 */
const Interfaces::ResponseInterface & Request::del(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

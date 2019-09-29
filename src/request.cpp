#include "http/request.h"

#include "http/types/common.h"

#include <string>
#include <sstream>
#include "http/response.h"

#include "http/exceptions/bad_connection_exception.h"
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


/**
 * Construct a request.
 */
Request::Request() : m_response(new Response)
{
    //
}

/**
 * Construct a request.
 *  
 * - initialize a response
 * 
 * @param Http::Interfaces::ResponseInterface * response
 */
Request::Request(Interfaces::ResponseInterface * response) : m_response(response)
{
    //
}

/**
 * Destruct the request.
 */
Request::~Request()
{
    delete m_response;
}

/**
 * Send a get request to given url.
 * 
 * @param const Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Request::get(const Interfaces::UrlInterface & url) const
{
    #if IS_WINDOWS
        // @todo write windows implemention
    #else
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) 
        {
            throw Exceptions::BadConnectionException();
        }

        unsigned int port = 80;
        if (!url.getPort().empty()) 
        {
            std::stringstream ss;
            ss << url.getPort();
            ss >> port;
        }

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        ::inet_pton(AF_INET, url.get().c_str(), &hint.sin_addr);

        int connectRes = ::connect(sock, (sockaddr*)&hint, sizeof(hint));
    #endif


    return m_response;
}

/**
 * Send a post request to given url.
 * 
 * @param const Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Request::post(const Interfaces::UrlInterface & url) const
{
    throw Exceptions::NotImplementedException();
}

/**
 * Send a put request to given url.
 * 
 * @param const Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Request::put(const Interfaces::UrlInterface & url) const
{
    throw Exceptions::NotImplementedException();
}

/**
 * Send a patch request to given url.
 * 
 * @param const Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Request::patch(const Interfaces::UrlInterface & url) const
{
    throw Exceptions::NotImplementedException();
}

/**
 * Send a delete request to given url.
 * 
 * @param const Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Request::del(const Interfaces::UrlInterface & url) const
{
    throw Exceptions::NotImplementedException();
}

/**
 * Retrieve the body stream.
 * 
 * @return Http::Interfaces::SocketStreamInterface *
 */
Interfaces::SocketStreamInterface * Request::getBody() const
{
    throw Exceptions::NotImplementedException();
}

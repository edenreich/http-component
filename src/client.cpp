#include "http/client.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


Client::Client() : m_request(Request()), m_response(Response())
{
    //
}

Client::Client(const Interfaces::RequestInterface & request, const Interfaces::ResponseInterface & response) : m_request(request), m_response(response)
{
    //
}

/**
 * Send a get request to given url.
 * 
 * @param const UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::get(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();

    return m_response;
}

/**
 * Send a post request to given url.
 * 
 * @param const UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::post(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();

    return m_response;
}

/**
 * Send a put request to given url.
 * 
 * @param const UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::put(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();

    return m_response;
}

/**
 * Send a patch request to given url.
 * 
 * @param const UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::patch(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();

    return m_response;
}

/**
 * Send a delete request to given url.
 * 
 * @param const UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::del(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();

    return m_response;
}

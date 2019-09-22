#include "http/client.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


/**
 * Construct a client.
 * 
 * - Initialize a request
 * 
 * @param const Interfaces::RequestInterface & request
 */
Client::Client(const Interfaces::RequestInterface & request) : m_request(request)
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
    return m_request.get(url); 
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

    return m_request.post(url);
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

    return m_request.put(url);
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

    return m_request.patch(url);
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

    return m_request.del(url);
}

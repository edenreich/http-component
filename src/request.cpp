#include "http/request.h"
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


Request::Request()
{
    //
}

/**
 * Send a get request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return Interfaces::ResponseInterface &
 */
Interfaces::ResponseInterface & Request::get(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a post request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return Interfaces::ResponseInterface &
 */
Interfaces::ResponseInterface & Request::post(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a put request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return Interfaces::ResponseInterface &
 */
Interfaces::ResponseInterface & Request::put(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a patch request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return Interfaces::ResponseInterface &
 */
Interfaces::ResponseInterface & Request::patch(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a delete request to given url.
 * 
 * @param const Interfaces::UrlInterface & url
 * @return Interfaces::ResponseInterface &
 */
Interfaces::ResponseInterface & Request::del(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

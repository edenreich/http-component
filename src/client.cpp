#include "http/client.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


Client::Client() : m_request(Request()), m_response(Response())
{
    //
}

Client:: Client(Interfaces::RequestInterface & request, Interfaces::ResponseInterface & response) : m_request(request), m_response(response)
{
    //
}

/**
 * Send a get request to given url.
 * 
 * @param const UrlInterface url
 * @return ResponseInterface
 */
Interfaces::ResponseInterface & get(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a post request to given url.
 * 
 * @param const UrlInterface url
 * @return ResponseInterface
 */
Interfaces::ResponseInterface & post(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a put request to given url.
 * 
 * @param const UrlInterface url
 * @return ResponseInterface
 */
Interfaces::ResponseInterface & put(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a patch request to given url.
 * 
 * @param const UrlInterface url
 * @return ResponseInterface
 */
Interfaces::ResponseInterface & patch(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}

/**
 * Send a delete request to given url.
 * 
 * @param const UrlInterface url
 * @return ResponseInterface
 */
Interfaces::ResponseInterface & del(const Interfaces::UrlInterface & url) const
{
    throw NotImplementedException();
}
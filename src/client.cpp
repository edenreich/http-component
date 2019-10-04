#include "http/client.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


/**
 * Construct a client.
 */
Client::Client() : m_request(nullptr)
{
    //
}

/**
 * Construct a client.
 * 
 * - Initialize a request
 * 
 * @param Http::Interfaces::RequestInterface * request
 */
Client::Client(Interfaces::RequestInterface * request) : m_request(request)
{
    //
}

/**
 * Destruct the client.
 */
Client::~Client()
{
    delete m_request;
}

/**
 * Sends a request by given type and url.
 * 
 * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
 * @param cost Http::Interfaces::UrlInterface & url
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Client::sendRequest(Verb verb, const Interfaces::UrlInterface & url) const
{
    Interfaces::RequestInterface * request;

    if (m_request == nullptr)
    {
        request = new Request(new Response());
    }
    else
    {
        request = m_request;
    }

    switch (verb) {
    case Verb::GET: return request->get(url);
    case Verb::POST: return request->post(url);
    case Verb::PUT: return request->put(url);
    case Verb::PATCH: return request->patch(url);
    case Verb::DEL: return request->del(url);
    }

    return request->get(url);
}

/**
 * Getter for the request.
 * 
 * @return Http::Interfaces::RequestInterface *
 */
Interfaces::RequestInterface * Client::getRequest() const
{
    return m_request;
}

/**
 * Getter for the response.
 * 
 * @return Http::Interfaces::ResponseInterface *
 */
Interfaces::ResponseInterface * Client::getResponse() const
{
    return new Response;
}

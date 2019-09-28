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
 * Sends a request by given type and url.
 * 
 * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
 * @param cost Http::Interfaces::UrlInterface & url
 * @return const ResponseInterface &
 */
const Interfaces::ResponseInterface & Client::sendRequest(Http::Verb verb, const Http::Interfaces::UrlInterface & url) const
{
    const Interfaces::RequestInterface & request = Request(Response());

    switch (verb) {
    case Verb::GET: return request.get(url);
    case Verb::POST: return request.post(url);
    case Verb::PUT: return request.put(url);
    case Verb::PATCH: return request.patch(url);
    case Verb::DELETE: return request.del(url);
    }
}

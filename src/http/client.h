#ifndef CLIENT_H
#define CLIENT_H

#include "interfaces/client_interface.h"
#include "interfaces/request_interface.h"
#include "interfaces/response_interface.h"

#include "types/verb.h"


namespace Http {

    /**
     * The Client Class
     */
    class Client : public Interfaces::ClientInterface {

    public:

        /**
         * Construct a client.
         * 
         * - Initialize a request
         * 
         * @param const Http::Interfaces::RequestInterface & request
         */
        Client(const Interfaces::RequestInterface & request);

        /**
         * Sends a request by given type and url.
         * 
         * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
         * @param cost Http::Interfaces::UrlInterface & url
         * @return const ResponseInterface &
         */
        const Interfaces::ResponseInterface & sendRequest(Verb verb, const Interfaces::UrlInterface & url) const override;

        /**
         * Getter for the request.
         * 
         * @return const Http::Interfaces::RequestInterface &
         */
        const Interfaces::RequestInterface & getRequest() const override;

    private:
        
        /**
         * Store the request.
         * 
         * @var const Http::Interfaces::RequestInterface &
         */
        const Interfaces::RequestInterface & m_request;

    };

}


#endif // CLIENT_H

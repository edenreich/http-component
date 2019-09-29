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
         */
        Client();

        /**
         * Construct a client.
         * 
         * - Initialize a request
         * 
         * @param Http::Interfaces::RequestInterface * request
         */
        Client(Interfaces::RequestInterface * request);

        /**
         * Destruct the client.
         */
        ~Client();

        /**
         * Sends a request by given type and url.
         * 
         * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
         * @param cost Http::Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * sendRequest(Verb verb, const Interfaces::UrlInterface & url) const override;

        /**
         * Getter for the request.
         * 
         * @return Http::Interfaces::RequestInterface *
         */
        Interfaces::RequestInterface * getRequest() const override;

        /**
         * Getter for the response.
         * 
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * getResponse() const override;

    private:
        
        /**
         * Store the request.
         * 
         * @var Http::Interfaces::RequestInterface *
         */
        Interfaces::RequestInterface * m_request;

    };

}


#endif // CLIENT_H

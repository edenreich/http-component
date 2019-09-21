#ifndef CLIENT_H
#define CLIENT_H

#include "interfaces/client_interface.h"
#include "interfaces/request_interface.h"
#include "interfaces/response_interface.h"


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
         * - Initialize a response
         * 
         * @param const Interfaces::RequestInterface & request
         * @param const Interfaces::RequestInterface & response
         */
        Client(const Interfaces::RequestInterface & request, const Interfaces::ResponseInterface & response);

        /**
         * Send a get request to given url.
         * 
         * @param const UrlInterface & url
         * @return const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & get(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a post request to given url.
         * 
         * @param const UrlInterface & url
         * @return const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & post(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a put request to given url.
         * 
         * @param const UrlInterface & url
         * @return const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & put(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a patch request to given url.
         * 
         * @param const UrlInterface & url
         * @return const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & patch(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a delete request to given url.
         * 
         * @param const UrlInterface & url
         * @return const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & del(const Interfaces::UrlInterface & url) const override;

    private:
        
        /**
         * Store the request.
         * 
         * @var const Interfaces::RequestInterface &
         */
        const Interfaces::RequestInterface & m_request;

        /**
         * Store the response.
         * 
         * @var const Interfaces::ResponseInterface &
         */
        const Interfaces::ResponseInterface & m_response;

    };

}


#endif // CLIENT_H

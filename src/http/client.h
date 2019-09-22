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
         * 
         * - Initialize a request
         * 
         * @param const Interfaces::RequestInterface & request
         */
        Client(const Interfaces::RequestInterface & request);

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

    };

}


#endif // CLIENT_H

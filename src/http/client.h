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
         * @param Interfaces::RequestInterface & request
         * @param Interfaces::RequestInterface & response
         */
        Client(Interfaces::RequestInterface & request, Interfaces::ResponseInterface & response);

        /**
         * Send a get request to given url.
         * 
         * @param const UrlInterface url
         * @return Interfaces::ResponseInterface &
         */
        Interfaces::ResponseInterface & get(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a post request to given url.
         * 
         * @param const UrlInterface url
         * @return Interfaces::ResponseInterface &
         */
        Interfaces::ResponseInterface & post(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a put request to given url.
         * 
         * @param const UrlInterface url
         * @return Interfaces::ResponseInterface &
         */
        Interfaces::ResponseInterface & put(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a patch request to given url.
         * 
         * @param const UrlInterface url
         * @return Interfaces::ResponseInterface &
         */
        Interfaces::ResponseInterface & patch(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a delete request to given url.
         * 
         * @param const UrlInterface url
         * @return Interfaces::ResponseInterface &
         */
        Interfaces::ResponseInterface & del(const Interfaces::UrlInterface & url) const override;

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

#ifndef REQUEST_H
#define REQUEST_H

#include "interfaces/request_interface.h"
#include "interfaces/url_interface.h"
#include "interfaces/response_interface.h"
#include "pch/network.h"


namespace Http {

    /**
     * The Request Class
     */
    class Request : public Interfaces::RequestInterface {

    public:

        /**
         * Construct a request.
         */
        Request();

        /**
         * Construct a request.
         *  
         * - initialize a response
         * 
         * @param Http::Interfaces::ResponseInterface * response
         */
        Request(Interfaces::ResponseInterface * response);

        /**
         * Destruct the request.
         */
        ~Request();

        /**
         * Send a get request to given url.
         * 
         * @param const Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * get(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a post request to given url.
         * 
         * @param const Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * post(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a put request to given url.
         * 
         * @param const Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * put(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a patch request to given url.
         * 
         * @param const Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * patch(const Interfaces::UrlInterface & url) const override;

        /**
         * Send a delete request to given url.
         * 
         * @param const Interfaces::UrlInterface & url
         * @return Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * del(const Interfaces::UrlInterface & url) const override;

        /**
         * Retrieve the body stream.
         * 
         * @return Http::Interfaces::StreamInterface *
         */
        Interfaces::StreamInterface * getBody() const override;

    private:
        
        /**
         * Store the response.
         * 
         * @var Http::Interfaces::ResponseInterface *
         */
        Interfaces::ResponseInterface * m_response;

    };

}


#endif // REQUEST_H

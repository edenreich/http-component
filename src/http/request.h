#ifndef REQUEST_H
#define REQUEST_H

#include "interfaces/request_interface.h"
#include "interfaces/url_interface.h"
#include "interfaces/response_interface.h"


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
             * Send a get request to given url.
             * 
             * @param const Interfaces::UrlInterface & url
             * @return const Interfaces::ResponseInterface &
             */
            const Interfaces::ResponseInterface & get(const Interfaces::UrlInterface & url) const override;

            /**
             * Send a post request to given url.
             * 
             * @param const Interfaces::UrlInterface & url
             * @return const Interfaces::ResponseInterface &
             */
            const Interfaces::ResponseInterface & post(const Interfaces::UrlInterface & url) const override;

            /**
             * Send a put request to given url.
             * 
             * @param const Interfaces::UrlInterface & url
             * @return const Interfaces::ResponseInterface &
             */
            const Interfaces::ResponseInterface & put(const Interfaces::UrlInterface & url) const override;

            /**
             * Send a patch request to given url.
             * 
             * @param const Interfaces::UrlInterface & url
             * @return const Interfaces::ResponseInterface &
             */
            const Interfaces::ResponseInterface & patch(const Interfaces::UrlInterface & url) const override;

            /**
             * Send a delete request to given url.
             * 
             * @param const Interfaces::UrlInterface & url
             * @return const Interfaces::ResponseInterface &
             */
            const Interfaces::ResponseInterface & del(const Interfaces::UrlInterface & url) const override;

    private:
        //

    };

}


#endif // REQUEST_H

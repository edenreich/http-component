#ifndef REQUEST_INTERFACE_H
#define REQUEST_INTERFACE_H

#include "url_interface.h"
#include <string>


namespace Http {
    namespace Interfaces {

        class ResponseInterface;

        /**
         * The Request Interface
         */
        class RequestInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~RequestInterface() {}
            
            /**
             * Send a get request to given url.
             * 
             * @param const UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & get(const UrlInterface & url) const = 0;

            /**
             * Send a post request to given url.
             * 
             * @param const UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & post(const UrlInterface & url) const = 0;

            /**
             * Send a put request to given url.
             * 
             * @param const UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & put(const UrlInterface & url) const = 0;

            /**
             * Send a patch request to given url.
             * 
             * @param const UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & patch(const UrlInterface & url) const = 0;

            /**
             * Send a delete request to given url.
             * 
             * @param const UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & del(const UrlInterface & url) const = 0;

        };
    }
}


#endif // REQUEST_INTERFACE_H

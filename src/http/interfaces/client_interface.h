#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H

#include "response_interface.h"
#include "url_interface.h"


namespace Http {
    namespace Interfaces {

        class UrlInterface;
        class ResponseInterface;

        /**
         * The Client Interface
         */
        class ClientInterface {

        public:
            
            /**
             * Get the response by given url.
             * 
             * @param UrlInterface url
             * @return ResponseInterface
             */
            virtual ResponseInterface get(UrlInterface & url) const = 0;

        };
    }
}


#endif // CLIENT_INTERFACE_H

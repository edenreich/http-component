#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H

#include "url_interface.h"
#include "response_interface.h"
#include "request_interface.h"


namespace Http {
  
    enum class Verb;

    namespace Interfaces {

        /**
         * The Client Interface
         */
        class ClientInterface {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~ClientInterface() {}
            
            /**
             * Sends a request by given type and url.
             * 
             * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
             * @param cost Http::Interfaces::UrlInterface & url
             * @return Http::Interfaces::ResponseInterface *
             */
            virtual ResponseInterface * sendRequest(::Http::Verb verb, const UrlInterface & url) const = 0;

            /**
             * Getter for the request.
             * 
             * @return Http::Interfaces::RequestInterface *
             */
            virtual RequestInterface * getRequest() const = 0;

            /**
             * Getter for the response.
             * 
             * @return Http::Interfaces::ResponseInterface *
             */
            virtual ResponseInterface * getResponse() const = 0;

        };
    }
}


#endif // CLIENT_INTERFACE_H

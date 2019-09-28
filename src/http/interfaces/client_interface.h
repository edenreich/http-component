#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H


namespace Http {
  
    enum class Verb;

    namespace Interfaces {

        class UrlInterface;
        class ResponseInterface;

        /**
         * The Client Interface
         */
        class ClientInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~ClientInterface() {}
            
            /**
             * Sends a request by given type and url.
             * 
             * @param Http::Verb::[GET|POST|PUT|PATCH|DELETE|HEAD]
             * @param cost Http::Interfaces::UrlInterface & url
             * @return const ResponseInterface &
             */
            virtual const ResponseInterface & sendRequest(Http::Verb verb, const Http::Interfaces::UrlInterface & url) const = 0;

        };
    }
}


#endif // CLIENT_INTERFACE_H

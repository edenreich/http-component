#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H


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
             * Virtual Destructor.
             */
            virtual ~ClientInterface();
            
            /**
             * Send a get request to given url.
             * 
             * @param const UrlInterface url
             * @return ResponseInterface &
             */
            virtual ResponseInterface & get(const UrlInterface & url) const = 0;

            /**
             * Send a post request to given url.
             * 
             * @param const UrlInterface url
             * @return ResponseInterface &
             */
            virtual ResponseInterface & post(const UrlInterface & url) const = 0;

            /**
             * Send a put request to given url.
             * 
             * @param const UrlInterface url
             * @return ResponseInterface &
             */
            virtual ResponseInterface & put(const UrlInterface & url) const = 0;

            /**
             * Send a patch request to given url.
             * 
             * @param const UrlInterface url
             * @return ResponseInterface &
             */
            virtual ResponseInterface & patch(const UrlInterface & url) const = 0;

            /**
             * Send a delete request to given url.
             * 
             * @param const UrlInterface url
             * @return ResponseInterface &
             */
            virtual ResponseInterface & del(const UrlInterface & url) const = 0;

        };
    }
}


#endif // CLIENT_INTERFACE_H

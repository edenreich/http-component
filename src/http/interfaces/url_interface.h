#ifndef URL_INTERFACE_H
#define URL_INTERFACE_H

#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Url Interface
         */
        class UrlInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~UrlInterface() {}

            /**
             * Retrieve the url.
             * 
             * @return std::string
             */
            virtual std::string get() const = 0;

            /**
             * Retrieve the encoded url.
             * 
             * @return std::string
             */
            virtual std::string getEncoded() const = 0;

            /**
             * Retrieve the decoded url.
             * 
             * @return std::string
             */
            virtual std::string getDecoded() const = 0;

            /**
             * Retrieve the scheme.
             * 
             * @return std::string
             */
            virtual std::string getScheme() const = 0;
        
            /**
             * Retrieve the host.
             * 
             * @return std::string
             */
            virtual std::string getHost() const = 0;

            /**
             * Retrieve the path.
             * 
             * @return std::string
             */
            virtual std::string getPath() const = 0;

        };
    }
}


#endif // URL_INTERFACE_H

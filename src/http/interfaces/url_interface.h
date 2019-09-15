#ifndef URL_INTERFACE_H
#define URL_INTERFACE_H

#include "url_interface.h"
#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Client Interface
         */
        class UrlInterface {

        public:

            /**
             * Retrieve the protocol.
             * 
             * @return std::string
             */
            virtual std::string getProtocol() const = 0;
        
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

            /**
             * Virtual destructor.
             */
            virtual ~UrlInterface() { }

        };
    }
}


#endif // URL_INTERFACE_H

#ifndef WRITABLE_SOCKET_INTERFACE_H
#define WRITABLE_SOCKET_INTERFACE_H

#include <string>
#include "../types/common.h"


namespace Http {
    namespace Interfaces {

        /**
         * The Writeable Socket Interface
         */
        class WriteableSocketInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~WriteableSocketInterface() {}

            /**
             * Setter for output stream - const char array variant.
             * 
             * @param const char * output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const char * output) = 0;

            /**
             * Setter for output stream - std::string variant.
             * 
             * @param const std::string & output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const std::string & output) = 0;

            /**
             * Setter for output stream - size_t variant.
             * 
             * @param const size_t & output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const size_t & output) = 0;

        };
    }
}


#endif // WRITABLE_SOCKET_INTERFACE_H

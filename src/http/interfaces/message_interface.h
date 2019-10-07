#ifndef MESSAGE_INTERFACE_H
#define MESSAGE_INTERFACE_H

#include "../types/message.h"

#include <string>
#include <sstream>


namespace Http {
    namespace Interfaces {

        /**
         * The Message Interface
         */
        class MessageInterface {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~MessageInterface() {}

            /**
             * Get the first line of the message.
             * 
             * @return const std::string &
             */
            virtual const std::string & getProtocolLine() const = 0;

            /**
             * Retrieve the message headers.
             * 
             * @return Http::Headers
             */
            virtual ::Http::Headers getHeaders() const = 0;

            /**
             * Retrieve the stream body.
             * 
             * @return const std::stringstream &
             */
            virtual const std::stringstream & getBody() const = 0;

            /**
             * Retrieve the raw message
             * with the protocol line,
             * headers and body.
             * 
             * @return const std::stringstream &
             */
            virtual const std::stringstream & getRaw() const = 0;

        };
    }
}


#endif // MESSAGE_INTERFACE_H

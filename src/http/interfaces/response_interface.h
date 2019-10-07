#ifndef RESPONSE_INTERFACE_H
#define RESPONSE_INTERFACE_H

#include "message_interface.h"


namespace Http {

    enum class StatusCode;

    namespace Interfaces {

        /**
         * The Response Interface
         */
        class ResponseInterface {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~ResponseInterface() {}
            
            /**
             * Retrieve the body stream.
             * 
             * @return const std::stringstream &
             */
            virtual const std::stringstream & getBody() const = 0;

            /**
             * Retrieve the message.
             * 
             * @return Http::Interfaces::MessageInterface *
             */
            virtual MessageInterface * getMessage() const = 0;

            /**
             * Retrieve the status code.
             * 
             * @return Http::StatusCode
             */
            virtual ::Http::StatusCode getStatusCode() = 0;

        };
    }
}


#endif // RESPONSE_INTERFACE_H

#ifndef RESPONSE_INTERFACE_H
#define RESPONSE_INTERFACE_H

#include "socket_stream_interface.h"


namespace Http {

    enum class StatusCode;

    namespace Interfaces {

        // class StreamInterface;

        /**
         * The Response Interface
         */
        class ResponseInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~ResponseInterface() = default;
            
            /**
             * Retrieve the body stream.
             * 
             * @return Http::Interfaces::SocketStreamInterface *
             */
            virtual SocketStreamInterface * getBody() const = 0;

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

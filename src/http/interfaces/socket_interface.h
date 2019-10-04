#ifndef SOCKET_INTERFACE_H
#define SOCKET_INTERFACE_H

#include "../types/common.h"


namespace Http {
    namespace Interfaces {

        /**
         * The Socket Interface
         */
        class SocketInterface {

        public:

            /**
             * Virtual destructor.
             */
            ~SocketInterface() {}

            /**
             * Set the id of the socket.
             * 
             * @param Http::SocketId socketId
             * @return void
             */
            virtual void setId(::Http::SocketId socketId) = 0;

            /**
             * Retrieve the id of the socket.
             * 
             * @return Http::SocketId
             */
            virtual const ::Http::SocketId & getId() const = 0;

            /**
             * Open the socket.
             * 
             * @return int
             */
            virtual int open() = 0;

            /**
             * Close the socket.
             * 
             * @return int
             */
            virtual int close() = 0;

        };
    }
}


#endif // SOCKET_INTERFACE_H

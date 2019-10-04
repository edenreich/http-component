#ifndef LISTENABLE_SOCKET_INTERFACE_H
#define LISTENABLE_SOCKET_INTERFACE_H

#include <string>


namespace Http {
    namespace Interfaces {

        class ReadableSocketInterface;

        /**
         * The Readable Stream Interface
         */
        class ListenableSocketInterface {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~ListenableSocketInterface() {}

            /**
             * Bind the address to the socket.
             * 
             * @param const std::string & address
             */
            virtual void bind(const std::string & address) = 0;

            /**
             * Wait for a connection.
             * 
             * @return Interfaces::ReadableSocketInterface *
             */
            virtual ReadableSocketInterface * waitForConnection() = 0;

        };
    }
}


#endif // LISTENABLE_SOCKET_INTERFACE_H

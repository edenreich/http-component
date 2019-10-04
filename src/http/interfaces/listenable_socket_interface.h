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
             * @return void
             */
            virtual void bind(const std::string & address) = 0;

            /**
             * Listen on a given port.
             * 
             * @param const unsigned int port
             * @return void
             */
            virtual void listen(const unsigned int port) = 0;

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

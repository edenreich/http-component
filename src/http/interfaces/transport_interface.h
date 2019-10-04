#ifndef TRANSPORT_INTERFACE_H
#define TRANSPORT_INTERFACE_H

#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Transferable Interface
         */
        class TransportInterface {

        public:

            /**
             * Virtual destructor.
             */
            ~TransportInterface() {}

            /**
             * Send a message on a socket.
             * 
             * @param const std::string & message
             * @return int
             */
            virtual int send(const std::string & message) const = 0;

        };
    }
}


#endif // TRANSFERABLE_SOCKET_INTERFACE_H

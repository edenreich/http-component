#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include "request_interface.h"
#include "server_interface.h"
#include "../events/common_events.h"
#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Server Interface
         */
        class ServerInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~ServerInterface() {}

            /**
             * Bind the server to specific address.
             * 
             * @param const std::string & address
             * @return void
             */
            virtual void bind(const std::string & address) = 0;

            /**
             * Start an http server on given port.
             * 
             * @param const unsigned int & port
             * @return void
             */
            virtual void listen(const unsigned int & port) = 0;

            /**
             * On data recieved event.
             * 
             * @param ::Http::Events::MessageRecievedHandler callback
             * @return void
             */
            virtual void onMessage(::Http::Events::MessageRecievedHandler callback) const = 0;

            /**
             * Close the http server.
             * 
             * @return void
             */
            virtual void close() = 0;

        };

    }
}


#endif // SERVER_INTERFACE_H

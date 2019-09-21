#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H


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
            virtual ~ServerInterface();

            /**
             * Start an http server on given port.
             * 
             * @return void
             */
            virtual void listen(unsigned int port) const = 0;

        };
    }
}


#endif // SERVER_INTERFACE_H

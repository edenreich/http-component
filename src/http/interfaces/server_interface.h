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
             * Start an http server on given port.
             * 
             * @return void
             */
            virtual void listen(unsigned int port) const = 0;

        };
    }
}


#endif // SERVER_INTERFACE_H

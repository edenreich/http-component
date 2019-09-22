#ifndef SERVER_H
#define SERVER_H

#include "interfaces/server_interface.h"


namespace Http {

    /**
     * The Server Class
     */
    class Server : public Interfaces::ServerInterface {

    public:

        /**
         * Construct a server
         */
        Server();

        /**
         * Bind the server to specific address.
         * 
         * @param const std::string & address
         * @return void
         */
        void bind(const std::string & address) const override;

        /**
         * Start an http server on given port.
         * 
         * @param unsigned int port
         * @return void
         */
        void listen(unsigned int port) const override;

        /**
         * On message recieved event.
         * 
         * @param Events::MessageRecievedHandler callback
         * @return void
         */
        void onMessage(Events::MessageRecievedHandler callback) const override;

        /**
         * Close the http server.
         * 
         * @return void
         */
        void close() const override;

    private:
        //

    };

}


#endif // SERVER_H

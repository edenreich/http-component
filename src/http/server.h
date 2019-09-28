#ifndef SERVER_H
#define SERVER_H

#include "interfaces/server_interface.h"
#include "pch/network.h"
#include <cstring>


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
        void bind(const std::string & address) override;

        /**
         * Start an http server on given port.
         * 
         * @param const unsigned int & port
         * @return void
         */
        void listen(const unsigned int & port) override;

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
        void close() override;

    private:
        
        /**
         * Store the server file descriptor.
         * 
         * @var int 
         */
        int m_server_fd;

        /**
         * Store the ip address.
         * 
         * @var const std::string &
         */
        std::string m_address;

        /**
         * Store the socket address.
         * 
         * @var struct sockaddr_in
         */
        struct sockaddr_in m_localaddr;

        /**
         * Determine if the server is running.
         * 
         * @var bool
         */
        bool m_running;

    };

}


#endif // SERVER_H

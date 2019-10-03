#ifndef SERVER_H
#define SERVER_H

#include "interfaces/server_interface.h"
#include "pch/network.h"
#include "socket_stream.h"
#include <atomic>


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
         * Destruct the server.
         */
        ~Server() override;

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
         * @param Http::Events::MessageRecievedHandler handler
         * @return void
         */
        void onConnection(Events::MessageRecievedHandler handler) override;

        /**
         * Shutdown the http server.
         * 
         * @return void
         */
        void shutdown() override;

    private:
        
        /**
         * Store the socket stream.
         * 
         * @var SocketStream *
         */
        SocketStream * m_socket;

        /**
         * Determine if the server is running.
         * 
         * @var std::atomic<bool> 
         */
        std::atomic<bool> m_running;

        /**
         * Store the ip address.
         * 
         * @var std::string
         */
        std::string m_address;

        /**
         * Store the port
         * 
         * @var unsigned int
         */
        unsigned int m_port;

    };

}


#endif // SERVER_H

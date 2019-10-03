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
         * @param Http::Events::MessageRecievedHandler callback
         * @return void
         */
        void onConnection(Events::MessageRecievedHandler callback) override;

        /**
         * Close the http server.
         * 
         * @return void
         */
        void close() override;

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

        std::string m_address;

        unsigned int m_port;
    };

}


#endif // SERVER_H

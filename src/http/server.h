#ifndef SERVER_H
#define SERVER_H

#include "interfaces/server_interface.h"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <unistd.h> 
    #include <stdlib.h> 
    #include <netinet/in.h>
    #include <arpa/inet.h>
#endif


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
        void close() const override;

    private:
        
        /**
         * Store the server file descriptor.
         * 
         * @var int 
         */
        int server_fd;

        /**
         * Store the ip address.
         * 
         * @var const std::string &
         */
        std::string m_address;

        /**
         * Store the socket address.
         * 
         * @var struct sockaddr_in *
         */
        struct sockaddr_in * m_localaddr;

    };

}


#endif // SERVER_H

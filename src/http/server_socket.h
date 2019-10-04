#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include "interfaces/server_socket_interface.h"

#include <sstream>
#include "pch/network.h"


namespace Http {

    /**
     * The Server Socket Class
     */
    class ServerSocket : public Interfaces::ServerSocketInterface
    {

    public:

        /**
         * Construct a socket stream.
         */
        ServerSocket();

        /**
         * Destruct the stream.
         */
        ~ServerSocket() override;

        /**
         * Set the id of the socket.
         * 
         * @param Http::SocketId socketId
         * @return void
         */
        void setId(SocketId socketId) override;

        /**
         * Retrieve the id of the socket.
         * 
         * @return Http::SocketId
         */
        const SocketId & getId() const override;

        /**
         * Open the socket.
         * 
         * @return int
         */
        int open() const override;

        /**
         * Close the socket.
         * 
         * @return int
         */
        int close() const override;

        /**
         * Bind the address to the socket.
         * 
         * @param const std::string & address
         */
        void bind(const std::string & address) override;

        /**
         * Wait for a connection.
         * 
         * @return Http::Interfaces::ClientSocketInterface *
         */
        Interfaces::ClientSocketInterface * waitForConnection() override;

        /**
         * Retrieve all content.
         * 
         * @return std::string
         */
        std::string getContents() const override;

        /**
         * Read data by given length.
         * 
         * @param unsigned int length
         * @return std::string
         */
        std::string read(unsigned int length) override;

        /**
         * Read a line.
         * 
         * @return std::string
         */
        std::string readLine() override;

        /**
         * Get the size.
         * 
         * @return unsigned int
         */
        unsigned int getSize() override;

        /**
         * Read the stream into variable.
         * 
         * @param std::string & input
         * @return Http::Interfaces::ReadableSocketInterface &
         */
        Interfaces::ReadableSocketInterface & operator>>(std::string & input) override;

        /**
         * Setter for output stream - const char array variant.
         * 
         * @param const char * output
         * @return const Interfaces::ServerSocketInterface &
         */
        Interfaces::ServerSocketInterface & operator<<(const char * output) override;

        /**
         * Setter for output stream - const ref std::string variant.
         * 
         * @param const std::string & output
         * @return const Interfaces::ServerSocketInterface &
         */
        Interfaces::ServerSocketInterface & operator<<(const std::string & output) override;

        /**
         * Setter for output stream - const ref size_t variant.
         * 
         * @param const size_t & output
         * @return const Interfaces::ServerSocketInterface &
         */
        Interfaces::ServerSocketInterface & operator<<(const size_t & output) override;

    private:

        /**
         * Store the socket id.
         * 
         * @var Http::SocketId m_socketId
         */ 
        SocketId m_socketId;

        /**
         * Store the contents.
         * 
         * @var std::stringstream
         */
        std::stringstream m_content;

        #if IS_WINDOWS
        /**
         * Store the address info.
         * 
         * @var struct addrinfo *
         */
        struct addrinfo * m_result;

        #else
        /**
         * Store the socket address.
         * 
         * @var struct sockaddr_in
         */
        struct sockaddr_in m_localaddr;

        #endif
    };

}


#endif // SERVER_SOCKET_H

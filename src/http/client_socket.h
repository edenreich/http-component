#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include "interfaces/client_socket_interface.h"

#include <sstream>
#include "pch/network.h"


namespace Http {

    /**
     * The Client Socket Class
     */
    class ClientSocket : public Interfaces::ClientSocketInterface {

    public:

        /**
         * Construct a socket.
         */
        ClientSocket();

        /**
         * Destruct the socket.
         */
        ~ClientSocket() override;

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
        int open() override;

        /**
         * Close the socket.
         * 
         * @return int
         */
        int close() override;

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
         * @param unsigned int number
         * @return std::string
         */
        std::string readLine(unsigned int number) override;

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
         * @return Http::Interfaces::WriteableSocketInterface &
         */
        WriteableSocketInterface & operator<<(const char * output) override;

        /**
         * Setter for output stream - std::string variant.
         * 
         * @param const std::string & output
         * @return Http::Interfaces::WriteableSocketInterface &
         */
        WriteableSocketInterface & operator<<(const std::string & output) override;

        /**
         * Setter for output stream - size_t variant.
         * 
         * @param const size_t & output
         * @return Http::Interfaces::WriteableSocketInterface &
         */
        WriteableSocketInterface & operator<<(const size_t & output) override;

        /**
         * Send a message on a socket.
         * 
         * @param const std::string & message
         * @return int
         */
        int send(const std::string & message) const override;

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


#endif // CLIENT_SOCKET_H

#ifndef SOCKET_STREAM_H
#define SOCKET_STREAM_H

#include "interfaces/socket_stream_interface.h"

#include <sstream>
#include "pch/network.h"


namespace Http {

    /**
     * The Stream Class
     */
    class SocketStream : public Interfaces::SocketStreamInterface {

    public:

        /**
         * Construct a socket stream.
         */
        SocketStream();

        /**
         * Destruct the stream.
         */
        ~SocketStream() override;

        /**
         * Retrieve the id of the socket.
         * 
         * @return Http::ServerSocketId
         */
        const ServerSocketId & getId() const override;

        /**
         * Bind the address to the socket.
         * 
         * @param const std::string & address
         */
        void bind(const std::string & address) override;

        /**
         * Wait for a connection.
         * 
         * @return Http::Interfaces::SocketStreamInterface *
         */
        Interfaces::SocketStreamInterface * waitForConnection() override;

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
         * Close the socket.
         * 
         * @return int
         */
        int close() const override;

        /**
         * Setter for output stream - const char array variant.
         * 
         * @param const char * output
         * @return const Interfaces::SocketStreamInterface &
         */
        Interfaces::SocketStreamInterface & operator<<(const char * output) override;

        /**
         * Setter for output stream - const ref std::string variant.
         * 
         * @param const std::string & output
         * @return const Interfaces::SocketStreamInterface &
         */
        Interfaces::SocketStreamInterface & operator<<(const std::string & output) override;

        /**
         * Setter for output stream - const ref size_t variant.
         * 
         * @param const size_t & output
         * @return const Interfaces::SocketStreamInterface &
         */
        Interfaces::SocketStreamInterface & operator<<(const size_t & output) override;

    private:

        /**
         * Store the file descriptor pointer.
         * 
         * @var Http::ServerSocketId m_socketId
         */ 
        ServerSocketId m_socketId;

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


#endif // SOCKET_STREAM_H

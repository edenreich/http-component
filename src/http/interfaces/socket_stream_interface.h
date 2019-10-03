#ifndef SOCKET_STREAM_INTERFACE_H
#define SOCKET_STREAM_INTERFACE_H

#include <string>
#include "../types/common.h"


namespace Http {
    namespace Interfaces {

        /**
         * The Stream Interface
         */
        class SocketStreamInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~SocketStreamInterface() {}

            /**
             * Retrieve the id of the socket.
             * 
             * @return Http::ServerSocketId
             */
            virtual const ::Http::ServerSocketId & getId() const = 0;

            /**
             * Bind the address to the socket.
             * 
             * @param const std::string & address
             */
            virtual void bind(const std::string & address) = 0;

            /**
             * Wait for a connection.
             * 
             * @return Interfaces::SocketStreamInterface *
             */
            virtual SocketStreamInterface * waitForConnection() = 0;
            
            /**
             * Retrieve all content.
             * 
             * @return std::string
             */
            virtual std::string getContents() const = 0;

            /**
             * Read data by given length.
             * 
             * @param unsigned int length
             * @return std::string
             */
            virtual std::string read(unsigned int length) = 0;

            /**
             * Read a line.
             * 
             * @return std::string
             */
            virtual std::string readLine() = 0;

            /**
             * Get the size.
             * 
             * @return unsigned int
             */
            virtual unsigned int getSize() = 0;

            /**
             * Close the socket.
             * 
             * @return int
             */
            virtual int close() const = 0;

            /**
             * Setter for output stream - const char array variant.
             * 
             * @param const char * output
             * @return SocketStreamInterface &
             */
            virtual SocketStreamInterface & operator<<(const char * output) = 0;

            /**
             * Setter for output stream - std::string variant.
             * 
             * @param const std::string & output
             * @return SocketStreamInterface &
             */
            virtual SocketStreamInterface & operator<<(const std::string & output) = 0;

            /**
             * Setter for output stream - size_t variant.
             * 
             * @param const size_t & output
             * @return SocketStreamInterface &
             */
            virtual SocketStreamInterface & operator<<(const size_t & output) = 0;

        };
    }
}


#endif // SOCKET_STREAM_INTERFACE_H

#ifndef CLIENT_SOCKET_INTERFACE_H
#define CLIENT_SOCKET_INTERFACE_H

#include "socket_interface.h"
#include "readable_socket_interface.h"
#include "writeable_socket_interface.h"

#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Client Socket Interface
         */
        class ClientSocketInterface : virtual public SocketInterface,
                                      virtual public ReadableSocketInterface,
                                      virtual public WriteableSocketInterface
        {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~ClientSocketInterface() {}

            /**
             * Set the id of the socket.
             * 
             * @param Http::SocketId socketId
             * @return void
             */
            virtual void setId(::Http::SocketId socketId) override = 0;

            /**
             * Retrieve the id of the socket.
             * 
             * @return Http::SocketId
             */
            virtual const ::Http::SocketId & getId() const override = 0;

            /**
             * Open the socket.
             * 
             * @return int
             */
            virtual int open() const override = 0;

            /**
             * Close the socket.
             * 
             * @return int
             */
            virtual int close() const override = 0;
            
            /**
             * Retrieve all content.
             * 
             * @return std::string
             */
            virtual std::string getContents() const override = 0;

            /**
             * Read data by given length.
             * 
             * @param unsigned int length
             * @return std::string
             */
            virtual std::string read(unsigned int length) override = 0;

            /**
             * Read a line.
             * 
             * @return std::string
             */
            virtual std::string readLine() override = 0;

            /**
             * Get the size.
             * 
             * @return unsigned int
             */
            virtual unsigned int getSize() override = 0;

            /**
             * Read the stream into variable.
             * 
             * @param std::string & input
             * @return Http::Interfaces::ReadableSocketInterface &
             */
            virtual ReadableSocketInterface & operator>>(std::string & input) override = 0;

            /**
             * Setter for output stream - const char array variant.
             * 
             * @param const char * output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const char * output) override = 0;

            /**
             * Setter for output stream - std::string variant.
             * 
             * @param const std::string & output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const std::string & output) override = 0;

            /**
             * Setter for output stream - size_t variant.
             * 
             * @param const size_t & output
             * @return Http::Interfaces::WriteableSocketInterface &
             */
            virtual WriteableSocketInterface & operator<<(const size_t & output) override = 0;

        };
    }
}


#endif // CLIENT_SOCKET_INTERFACE_H

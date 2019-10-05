#ifndef READABLE_SOCKET_INTERFACE_H
#define READABLE_SOCKET_INTERFACE_H

#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Readable Socket Interface
         */
        class ReadableSocketInterface {

        public:

            /**
             * Virtual destructor.
             */
            virtual ~ReadableSocketInterface() {}
            
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
             * @param unsigned int number
             * @return std::string
             */
            virtual std::string readLine(unsigned int number) = 0;

            /**
             * Get the size.
             * 
             * @return unsigned int
             */
            virtual unsigned int getSize() = 0;

            /**
             * Read the stream into variable.
             * 
             * @param std::string & input
             * @return Http::Interfaces::ReadableSocketInterface &
             */
            virtual ReadableSocketInterface & operator>>(std::string & input) = 0;

        };
    }
}


#endif // READABLE_SOCKET_INTERFACE_H

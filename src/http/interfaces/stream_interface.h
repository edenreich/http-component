#ifndef STREAM_INTERFACE_H
#define STREAM_INTERFACE_H

#include <string>


namespace Http {
    namespace Interfaces {

        /**
         * The Stream Interface
         */
        class StreamInterface {

        public:
            
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
            virtual std::string read(unsigned int length) const = 0;

            /**
             * Read a line.
             * 
             * @return std::string
             */
            virtual std::string readLine() const = 0;

            /**
             * Get the size.
             * 
             * @return unsigned int
             */
            virtual unsigned int getSize() const = 0;

        };
    }
}


#endif // STREAM_INTERFACE_H

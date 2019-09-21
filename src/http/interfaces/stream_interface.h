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
             * Retrieve the raw body.
             * 
             * @return std::string
             */
            virtual std::string getContents() const = 0;

            /**
             * Read data from the stream.
             * 
             * @param unsigned int length
             * @return std::string
             */
            virtual std::string read(unsigned int length) const = 0;

        };
    }
}


#endif // STREAM_INTERFACE_H

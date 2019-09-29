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
             * Virtual Destructor.
             */
            virtual ~StreamInterface() = default;
            
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
             * Setter for output stream - const char array variant.
             * 
             * @param const char * output
             * @return const StreamInterface &
             */
            virtual StreamInterface & operator<<(const char * output) = 0;

            /**
             * Setter for output stream - std::string variant.
             * 
             * @param const std::string & output
             * @return const StreamInterface &
             */
            virtual StreamInterface & operator<<(const std::string & output) = 0;

            /**
             * Setter for output stream - size_t variant.
             * 
             * @param const size_t & output
             * @return const StreamInterface &
             */
            virtual StreamInterface & operator<<(const size_t & output) = 0;

        };
    }
}


#endif // STREAM_INTERFACE_H

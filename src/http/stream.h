#ifndef STREAM_H
#define STREAM_H

#include "interfaces/stream_interface.h"

#include <sstream>


namespace Http {

    /**
     * The Stream Class
     */
    class Stream : public Interfaces::StreamInterface {

    public:

        /**
         * Construct a stream.
         */
        Stream();

        /**
         * Construct a stream.
         * 
         * - initialize a file descriptor.
         * 
         * @param int * fileDescriptor
         */
        Stream(int * fileDescriptor);

        /**
         * Destruct the stream.
         */
        ~Stream();

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
         * Setter for output stream - const char array variant.
         * 
         * @param const char * output
         * @return const Interfaces::StreamInterface &
         */
        Interfaces::StreamInterface & operator<<(const char * output) override;

        /**
         * Setter for output stream - const ref std::string variant.
         * 
         * @param const std::string & output
         * @return const Interfaces::StreamInterface &
         */
        Interfaces::StreamInterface & operator<<(const std::string & output) override;

        /**
         * Setter for output stream - const ref size_t variant.
         * 
         * @param const size_t & output
         * @return const Interfaces::StreamInterface &
         */
        Interfaces::StreamInterface & operator<<(const size_t & output) override;

    private:
        
        /**
         * Store the pointer to the file descriptor.
         * 
         * @var int * m_fileDescriptor
         */
        int * m_fileDescriptor;

        /**
         * Store the contents.
         * 
         * @var std::stringstream
         */
        std::stringstream m_content;

    };

}


#endif // STREAM_H

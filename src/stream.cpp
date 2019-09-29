#include "http/socket_stream.h"

#include "pch/network.h"
#include <ios>

using namespace Http;


/**
 * Construct a socket stream.
 */
SocketStream::SocketStream() : m_fileDescriptor(nullptr)
{
    //
}

/**
 * Construct a stream.
 * 
 * - initialize a file descriptor
 * 
 * @param int fileDescriptor
 */
SocketStream::SocketStream(int * fileDescriptor) : m_fileDescriptor(fileDescriptor)
{
    //
}

/**
 * Destruct the stream.
 */
SocketStream::~SocketStream()
{
    delete m_fileDescriptor;
}

/**
 * Retrieve all content.
 * 
 * @return std::string
 */
std::string SocketStream::getContents() const
{
    return m_content.str();
}

/**
 * Read data by given length.
 * 
 * @param unsigned int length
 * @return std::string
 */
std::string SocketStream::read(unsigned int length)
{
    std::string chunk;

    chunk.reserve(length);

    m_content >> chunk;

    return chunk;
}

/**
 * Read a line.
 * 
 * @return std::string
 */
std::string SocketStream::readLine()
{
    std::string line;

    std::getline(m_content, line);

    return line;
}

/**
 * Get the size.
 * 
 * @return unsigned int
 */
unsigned int SocketStream::getSize()
{
    m_content.seekg(0, std::ios::end);

    unsigned int size = m_content.tellg();

    m_content.seekg(0, std::ios::beg);

    return size;
}

/**
 * Setter for output stream - const char array variant.
 * 
 * @param const char * output
 * @return Http::Interfaces::SocketStreamInterface &
 */
Interfaces::SocketStreamInterface & SocketStream::operator<<(const char * output) 
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref std::string variant.
 * 
 * @param const std::string & output
 * @return Http::Interfaces::SocketStreamInterface &
 */
Interfaces::SocketStreamInterface & SocketStream::operator<<(const std::string & output)
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref size_t variant.
 * 
 * @param const size_t & output
 * @return Http::Interfaces::SocketStreamInterface
 */
Interfaces::SocketStreamInterface & SocketStream::operator<<(const size_t & output)
{
    m_content << output;

    return *this;
}

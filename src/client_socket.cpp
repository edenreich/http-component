#include "http/client_socket.h"

#include "http/platform/check.h"

#include "http/exceptions/bad_connection_exception.h"

#include <ios>
#include <cstring>

using namespace Http;


/**
 * Construct a socket.
 */
ClientSocket::ClientSocket() : m_socketId(0), m_content(std::stringstream())
{

}

/**
 * Destruct the stream.
 */
ClientSocket::~ClientSocket()
{
    #if IS_WINDOWS
    ::freeaddrinfo(m_result);
    ::WSACleanup();
    #else

    #endif
}

/**
 * Set the id of the socket.
 * 
 * @param Http::SocketId socketId
 * @return void
 */
void ClientSocket::setId(SocketId socketId)
{
    m_socketId = socketId;
}

/**
 * Retrieve the id of the socket.
 * 
 * @return Http::SocketId
 */
const SocketId & ClientSocket::getId() const
{
    return m_socketId;
}

/**
 * Close the socket.
 * 
 * @return int
 */
int ClientSocket::close()
{
    int result;

    #if IS_WINDOWS
    result = ::closesocket(m_socketId);
    #else
    result = ::close(m_socketId);
    #endif

    return result;
}

/**
 * Open the socket.
 * 
 * @return int
 */
int ClientSocket::open()
{
    int result = 0;

    return result;
}

/**
 * Retrieve all content.
 * 
 * @return std::string
 */
std::string ClientSocket::getContents() const
{
    return m_content.str();
}

/**
 * Read data by given length.
 * 
 * @param unsigned int length
 * @return std::string
 */
std::string ClientSocket::read(unsigned int length)
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
std::string ClientSocket::readLine()
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
unsigned int ClientSocket::getSize()
{
    m_content.seekg(0, std::ios::end);

    #pragma warning(push)
    #pragma warning(disable: 4244)
    unsigned int size = m_content.tellg();
    #pragma warning(pop)
    
    m_content.seekg(0, std::ios::beg);

    return size;
}

/**
 * Read the stream into variable.
 * 
 * @param std::string & input
 * @return Http::Interfaces::ReadableSocketInterface &
 */
Interfaces::ReadableSocketInterface & ClientSocket::operator>>(std::string & input)
{
    m_content >> input;

    return *this;
}

/**
 * Setter for output stream - const char array variant.
 * 
 * @param const char * output
 * @return Http::Interfaces::WriteableSocketInterface &
 */
Interfaces::WriteableSocketInterface & ClientSocket::operator<<(const char * output) 
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref std::string variant.
 * 
 * @param const std::string & output
 * @return Http::Interfaces::WriteableSocketInterface &
 */
Interfaces::WriteableSocketInterface & ClientSocket::operator<<(const std::string & output)
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref size_t variant.
 * 
 * @param const size_t & output
 * @return Http::Interfaces::WriteableSocketInterface &
 */
Interfaces::WriteableSocketInterface & ClientSocket::operator<<(const size_t & output)
{
    m_content << output;

    return *this;
}

/**
 * Send a message on a socket.
 * 
 * @param const std::string & message
 * @return int
 */
int ClientSocket::send(const std::string & message) const
{
    int result = 0;

    #if IS_WINDOWS
        //
    #else
    const char * cmessage = message.c_str();
    int bufferLength = message.length();

    result = ::send(m_socketId, cmessage, bufferLength, 0);
    #endif

    return result;
}
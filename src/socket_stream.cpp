#include "http/socket_stream.h"

#include "http/platform/check.h"

#include "http/exceptions/bad_connection_exception.h"
#include <ios>

using namespace Http;


/**
 * Construct a socket stream.
 */
SocketStream::SocketStream() : m_socketId(0), m_content(std::stringstream()), m_localaddr{} 
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    m_socketId = ::socket(AF_INET, SOCK_STREAM, 0);

    if (m_socketId == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not create the socket");
    }
    #endif
}

/**
 * Destruct the stream.
 */
SocketStream::~SocketStream()
{
    //
}

/**
 * Retrieve the id of the socket.
 * 
 * @return unsigned int
 */
const unsigned int & SocketStream::getId() const
{
    return m_socketId;
}

void SocketStream::bind(const std::string & address)
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    int opt = 1;

    m_localaddr.sin_family = AF_INET;
    m_localaddr.sin_addr.s_addr = ::inet_addr(address.c_str());
    m_localaddr.sin_port = htons(8080); 

    if (::setsockopt(m_socketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        throw Exceptions::BadConnectionException("Setsockopt failed");
    } 

    int failed = ::bind(m_socketId, (struct sockaddr *)&m_localaddr, sizeof(m_localaddr));

    if (m_socketId == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind the socket to address!");
    }

    if (failed < 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind to the given port");
    }
    #endif
}

/**
 * Wait for a connection.
 */
const int SocketStream::waitForConnection() const
{
    int addresslen = sizeof(m_localaddr);
    int clientSocket;

    #if IS_WINDOWS
        // @todo write windows specific implemention
    #else
    if ((clientSocket = ::accept(m_socketId, (struct sockaddr *)&m_localaddr, (socklen_t*)&addresslen)) < 0)
    {
        throw Exceptions::BadConnectionException("Could not accept the connection");
    }
    #endif

    return clientSocket;
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
 * @return Http::Interfaces::SocketStreamInterface &
 */
Interfaces::SocketStreamInterface & SocketStream::operator<<(const size_t & output)
{
    m_content << output;

    return *this;
}

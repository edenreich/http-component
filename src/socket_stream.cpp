#include "http/socket_stream.h"

#include "http/platform/check.h"

#include "http/exceptions/bad_connection_exception.h"
#include <ios>

using namespace Http;


/**
 * Construct a socket stream.
 */
SocketStream::SocketStream() : m_socketId(0), m_content(std::stringstream())
{
    #if IS_WINDOWS
    m_result = NULL;
    int iResult;
    struct addrinfo hints;
    WSADATA wsaData;

    SOCKET m_socketId = INVALID_SOCKET;

    iResult = ::WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) 
    {
        throw Exceptions::BadConnectionException("Could not create the socket");
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = ::getaddrinfo(NULL, "80", &hints, &m_result);
    if (iResult != 0) {
        ::WSACleanup();
        throw Exceptions::BadConnectionException("Could not create the socket");
    }

    m_socketId = ::socket(m_result->ai_family, m_result->ai_socktype, m_result->ai_protocol);
    if (m_socketId == INVALID_SOCKET) {
        ::freeaddrinfo(m_result);
        ::WSACleanup();
        throw Exceptions::BadConnectionException("Could not create the socket");
    }
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
 * @return Http::ServerSocketId
 */
const ServerSocketId & SocketStream::getId() const
{
    return m_socketId;
}

void SocketStream::bind(const std::string & address)
{
    #if IS_WINDOWS
    int iResult;
    iResult = ::bind(m_socketId, m_result->ai_addr, (int)m_result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        ::freeaddrinfo(m_result);
        ::closesocket(m_socketId);
        ::WSACleanup();
        throw Exceptions::BadConnectionException("Faild to bind socket to address");
    }

    ::freeaddrinfo(m_result);
    #else
    int opt = 1;

    m_localaddr.sin_family = AF_INET;
    m_localaddr.sin_addr.s_addr = ::inet_addr(address.c_str());
    m_localaddr.sin_port = htons(8080); 

    if (::setsockopt(m_socketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        throw Exceptions::BadConnectionException("Faild to bind socket to address");
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
 * 
 * @return const Http::ClientSocketId
 */
const ClientSocketId SocketStream::waitForConnection() const
{
    ClientSocketId clientSocketId;

    #if IS_WINDOWS
    clientSocketId = ::accept(m_socketId, NULL, NULL);
    if (clientSocketId == INVALID_SOCKET) {
        throw Exceptions::BadConnectionException("Could not accept the connection");
        ::closesocket(m_socketId);
        ::WSACleanup();
    }
    #else
    int addresslen = sizeof(m_localaddr);
    if ((clientSocketId = ::accept(m_socketId, (struct sockaddr *)&m_localaddr, (socklen_t*)&addresslen)) < 0) {
        throw Exceptions::BadConnectionException("Could not accept the connection");
    }
    #endif

    return clientSocketId;
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

    #pragma warning(push)
    #pragma warning(disable: 4244)
    unsigned int size = m_content.tellg();
    #pragma warning(pop)
    
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

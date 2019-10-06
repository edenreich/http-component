#include "http/server_socket.h"
#include "http/client_socket.h"

#include "http/platform/check.h"

#include "http/exceptions/bad_connection_exception.h"

#include <ios>

using namespace Http;


/**
 * Construct a socket.
 */
ServerSocket::ServerSocket() : m_socketId(0), m_content(std::stringstream())
{
    #if IS_WINDOWS
    m_result = NULL;
    m_socketId = INVALID_SOCKET;
    #else
    //
    #endif
}

/**
 * Destruct the stream.
 */
ServerSocket::~ServerSocket()
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
void ServerSocket::setId(SocketId socketId)
{
    m_socketId = socketId;
}

/**
 * Retrieve the id of the socket.
 * 
 * @return Http::SocketId
 */
const SocketId & ServerSocket::getId() const
{
    return m_socketId;
}

/**
 * Open the socket.
 * 
 * @return int
 */
int ServerSocket::open()
{
    int result;

    #if IS_WINDOWS

    WSADATA wsaData;
    result = ::WSAStartup(MAKEWORD(2,2), &wsaData);
    
    if (result != 0) 
    {
        throw Exceptions::BadConnectionException("Could not create the socket");
    }

    m_socketId = ::socket(m_result->ai_family, m_result->ai_socktype, m_result->ai_protocol);
    if (m_socketId == INVALID_SOCKET) {
        throw Exceptions::BadConnectionException("Could not create the socket");
    }
    #else
    int opt = 1;
    m_socketId = ::socket(AF_INET, SOCK_STREAM, 0);

    if (m_socketId == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not create the socket");
    }

    if (::setsockopt(m_socketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        throw Exceptions::BadConnectionException("Faild to bind socket to address");
    }
    #endif

    return result;
}

/**
 * Close the socket.
 * 
 * @return int
 */
int ServerSocket::close()
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
 * Retrieve all content.
 * 
 * @return std::string
 */
std::string ServerSocket::getContents()
{
    return m_content.str();
}

/**
 * Read data by given length.
 * 
 * @param unsigned int length
 * @return std::string
 */
std::string ServerSocket::read(unsigned int length)
{
    std::string chunk;

    chunk.reserve(length);

    m_content >> chunk;

    return chunk;
}

/**
 * Read a line.
 * 
 * @param unsigned int number
 * @return std::string
 */
std::string ServerSocket::readLine(unsigned int number)
{
    std::string line;

    do
    {
        std::getline(m_content, line);
        
        if (line[line.size()-1] == '\r') {
            line = line.substr(0, line.size()-1);
        }

        number--;
    } while (std::string::npos != m_content.str().find('\n') && number != 0);

    return line;
}

/**
 * Get the size.
 * 
 * @return unsigned int
 */
unsigned int ServerSocket::getSize()
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
Interfaces::ReadableSocketInterface & ServerSocket::operator>>(std::string & input)
{
    m_content >> input;

    return *this;
}

/**
 * Setter for output stream - const char array variant.
 * 
 * @param const char * output
 * @return Http::Interfaces::ServerSocketInterface &
 */
Interfaces::ServerSocketInterface & ServerSocket::operator<<(const char * output) 
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref std::string variant.
 * 
 * @param const std::string & output
 * @return Http::Interfaces::ServerSocketInterface &
 */
Interfaces::ServerSocketInterface & ServerSocket::operator<<(const std::string & output)
{
    m_content << output;

    return *this;
}

/**
 * Setter for output stream - const ref size_t variant.
 * 
 * @param const size_t & output
 * @return Http::Interfaces::ServerSocketInterface &
 */
Interfaces::ServerSocketInterface & ServerSocket::operator<<(const size_t & output)
{
    m_content << output;

    return *this;
}

/**
 * Bind the address to the socket.
 * 
 * @param const std::string & address
 * @return void
 */
void ServerSocket::bind(const std::string & address)
{
    int result;

    #if IS_WINDOWS
    struct addrinfo service;

    ZeroMemory(&service, sizeof(service));
    service.ai_family = AF_INET;
    service.ai_socktype = SOCK_STREAM;
    service.ai_protocol = IPPROTO_TCP;
    service.ai_flags = AI_PASSIVE;

    result = ::getaddrinfo(NULL, address.c_str(), &service, &m_result);
    if (result != 0) {
        throw Exceptions::BadConnectionException("Could not create the socket");
    }

    result = ::bind(m_socketId, m_result->ai_addr, (int)m_result->ai_addrlen);
    if (result == SOCKET_ERROR) {
        throw Exceptions::BadConnectionException("Faild to bind socket to address");
    }
    #else
    m_localaddr.sin_family = AF_INET;
    m_localaddr.sin_port = htons(8080);
    m_localaddr.sin_addr.s_addr = ::inet_addr(address.c_str());
    
    result = ::bind(m_socketId, (struct sockaddr *)&m_localaddr, sizeof(m_localaddr));

    if (m_socketId == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind the socket to address!");
    }

    if (result < 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind to the given port");
    }
    #endif
}

/**
 * Listen on a given port.
 * 
 * @param const unsigned int port
 * @return void
 */
void ServerSocket::listen(const unsigned int port)
{
    #if IS_WINDOWS
    int result = ::listen(m_socketId, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        throw Exceptions::BadConnectionException("Could not listen on the given port");
    }
    #else
    if (::listen(getId(), 1) < 0) { 
        throw Exceptions::BadConnectionException("Could not listen on the given port");
    }
    #endif
}

/**
 * Wait for a connection.
 * 
 * @return Http::Interfaces::ClientSocketInterface *
 */
Interfaces::ClientSocketInterface * ServerSocket::waitForConnection()
{
    Interfaces::ClientSocketInterface * socket = new ClientSocket;

    #if IS_WINDOWS
    SocketId socketId;

    socketId = ::accept(m_socketId, NULL, NULL);
    if (socketId == INVALID_SOCKET) {
        throw Exceptions::BadConnectionException("Could not accept the connection");
    }
    #else
    int addresslen = sizeof(m_localaddr);

    SocketId socketId = 0;

    if ((socketId = ::accept(m_socketId, (struct sockaddr *)&m_localaddr, (socklen_t*)&addresslen)) < 0) {
        throw Exceptions::BadConnectionException("Could not accept the connection");
    }
    #endif

    socket->setId(socketId);

    return socket;
}

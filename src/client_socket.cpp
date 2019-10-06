#include "http/client_socket.h"

#include "http/platform/check.h"

#include "http/exceptions/invalid_client_socket_exception.h"
#include "http/exceptions/bad_connection_exception.h"

#include <ios>
#include <iomanip>
#include <cstring>

using namespace Http;

#define MESSAGE_MAX_SIZE 6000


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
std::string ClientSocket::getContents()
{
    parseSocketData();

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
    parseSocketData();

    std::stringstream message;
    char * messageBuffer = new char[length];
    
    m_content.read(messageBuffer, length);
    m_content.seekg(0, std::ios::beg);

    message << messageBuffer;

    delete messageBuffer;

    return message.str();
}

/**
 * Read a line.
 * 
 * @param unsigned int number
 * @return std::string
 */
std::string ClientSocket::readLine(unsigned int number)
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
    result = ::send(m_socketId, message.c_str(), message.length(), 0);
    #endif

    return result;
}

/**
 * Parse the socket and load all data
 * to class member.
 * 
 * @return void
 */
void ClientSocket::parseSocketData()
{
    char * buffer = nullptr;

    if (m_content.str().empty()) {

        buffer = new char[MESSAGE_MAX_SIZE];
            
        ::read(m_socketId, buffer, MESSAGE_MAX_SIZE);

        m_content << buffer;

        delete buffer;
    }
}
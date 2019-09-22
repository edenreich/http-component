#include "http/server.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"
#include "http/exceptions/bad_connection_exception.h"

using namespace Http;


/**
 * Construct a server
 */
Server::Server() : m_server_fd(::socket(AF_INET, SOCK_STREAM, 0)), m_address(std::string()), m_running(false)
{
    if (m_server_fd == 0) 
    { 
        throw BadConnectionException("Could not create the socket");
    } 
}

/**
 * Bind the server to specific address.
 * 
 * @param const std::string & address
 * @return void
 */
void Server::bind(const std::string & address)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        // @todo write windows specific implemention
    #else
        int opt = 1;
        m_address = address;
        m_localaddr.sin_family = AF_INET;
        m_localaddr.sin_addr.s_addr = inet_addr(m_address.c_str());
        m_localaddr.sin_port = htons(8080); 

        if (::setsockopt(m_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
        {
            throw BadConnectionException("Setsockopt failed");
        } 

        int failed = ::bind(m_server_fd, (struct sockaddr *)&m_localaddr, sizeof(m_localaddr));

        if (m_server_fd == 0) 
        { 
            throw BadConnectionException("Could not bind the server to address!");
        }

        if (failed < 0) 
        { 
            throw BadConnectionException("Could not bind to the given port");
        }
    #endif
}

/**
 * Start an http server on given port.
 * 
 * @param const unsigned int & port
 * @return void
 */
void Server::listen(const unsigned int & port)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        // @todo write windows specific implemention
    #else
        if (::listen(m_server_fd, 3) < 0) 
        { 
            throw BadConnectionException("Could not listen on the given port");
        }
    #endif

    m_running = true;
}

/**
 * On data recieved event.
 * 
 * @param Events::MessageRecievedHandler callback
 * @return void
 */
void Server::onMessage(Events::MessageRecievedHandler callback) const
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        // @todo write windows specific implemention
    #else
        int clientConnection;
        char buffer[1024] = {0};
        int addresslen = sizeof(m_localaddr);

        while (m_running) {
            if ((clientConnection = ::accept(m_server_fd, (struct sockaddr *)&m_localaddr, (socklen_t*)&addresslen)) < 0)
            {
                throw BadConnectionException("Could not accept the connection");
            }

            int dataLength = ::read(clientConnection, buffer, 1024);

            callback(this, buffer);

            ::close(clientConnection);
        }
    #endif
}

/**
 * Close the http server.
 * 
 * @return void
 */
void Server::close()
{
    m_running = false;
}
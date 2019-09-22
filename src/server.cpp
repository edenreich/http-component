#include "http/server.h"
#include "http/request.h"
#include "http/response.h"

#include "http/exceptions/not_implemented_exception.h"
#include "http/exceptions/bad_connection_exception.h"

using namespace Http;


/**
 * Construct a server
 */
Server::Server() : server_fd(socket(AF_INET, SOCK_STREAM, 0)), m_address(std::string())
{

}

/**
 * Bind the server to specific address.
 * 
 * @param const std::string & address
 * @return void
 */
void Server::bind(const std::string & address)
{
    m_address = address;

    m_localaddr->sin_family = AF_INET;
    m_localaddr->sin_addr.s_addr = inet_addr(m_address.c_str());
    ::bind(server_fd, (struct sockaddr *)&m_localaddr, sizeof(m_localaddr));
}

/**
 * Start an http server on given port.
 * 
 * @param const unsigned int & port
 * @return void
 */
void Server::listen(const unsigned int & port)
{
    m_localaddr->sin_port = htons(port);

    ::listen(server_fd, 0);
}

/**
 * On data recieved event.
 * 
 * @param Events::MessageRecievedHandler callback
 * @return void
 */
void Server::onMessage(Events::MessageRecievedHandler callback) const
{
    int newSocket;
    char buffer[1024] = {0};

    if ((newSocket = accept(server_fd, (struct sockaddr *)&m_localaddr, (socklen_t*)&m_localaddr)) < 0)
    {
        throw BadConnectionException("Could not accept connections");
    }

    int valread = read(newSocket, buffer, 1024); 

    callback(this, buffer);
}

/**
 * Close the http server.
 * 
 * @return void
 */
void Server::close() const
{
    throw NotImplementedException();
}
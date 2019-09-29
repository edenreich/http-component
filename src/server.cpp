#include "http/server.h"

#include "http/types/common.h"

#include "http/client.h"
#include "http/request.h"
#include "http/response.h"
#include "http/socket_stream.h"

#include "http/exceptions/not_implemented_exception.h"
#include "http/exceptions/bad_connection_exception.h"

using namespace Http;


/**
 * Construct a server
 */
Server::Server() : m_address(std::string()), m_running(false)
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    m_serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);

    if (m_serverSocket == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not create the socket");
    }
    #endif
}

/**
 * Bind the server to specific address.
 * 
 * @param const std::string & address
 * @return void
 */
void Server::bind(const std::string & address)
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    int opt = 1;
    m_address = address;
    m_localaddr.sin_family = AF_INET;
    m_localaddr.sin_addr.s_addr = ::inet_addr(m_address.c_str());
    m_localaddr.sin_port = htons(8080); 

    if (::setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        throw Exceptions::BadConnectionException("Setsockopt failed");
    } 

    int failed = ::bind(m_serverSocket, (struct sockaddr *)&m_localaddr, sizeof(m_localaddr));

    if (m_serverSocket == 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind the server to address!");
    }

    if (failed < 0) 
    { 
        throw Exceptions::BadConnectionException("Could not bind to the given port");
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
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    if (::listen(m_serverSocket, 3) < 0) 
    { 
        throw Exceptions::BadConnectionException("Could not listen on the given port");
    }
    #endif

    m_running = true;
}

/**
 * On data recieved event.
 * 
 * @param Http::Events::MessageRecievedHandler callback
 * @return void
 */
void Server::onConnection(Events::MessageRecievedHandler callback)
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else        
    int addresslen = sizeof(m_localaddr);

    while (m_running) {
        int clientSocket;

        if ((clientSocket = ::accept(m_serverSocket, (struct sockaddr *)&m_localaddr, (socklen_t*)&addresslen)) < 0)
        {
            throw Exceptions::BadConnectionException("Could not accept the connection");
        }

        // // Client Request
        // Interfaces::StreamInterface * stream = new Stream();
        // Interfaces::ResponseInterface * response = new Response(stream);
        // Interfaces::RequestInterface * request = new Request(response);
        // Interfaces::ClientInterface * client = new Client(request);

        // // Server Response
        // Interfaces::ResponseInterface * serverResponse = callback(client);
        // Interfaces::StreamInterface * serverStream = serverResponse->getBody();

        // ::send(clientSocket, serverStream->getContents().c_str(), strlen(serverStream->getContents().c_str()), 0);

        // ::close(clientSocket);
        // ::close(m_serverSocket);

        // delete client;
        // delete serverResponse;
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
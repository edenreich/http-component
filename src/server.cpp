#include "http/server.h"

#include "http/platform/check.h"

#include "http/client.h"
#include "http/request.h"
#include "http/response.h"
#include "http/socket_stream.h"

#include "http/exceptions/not_implemented_exception.h"
#include "http/exceptions/bad_connection_exception.h"

#include <cstring>
#include <iostream>

using namespace Http;


/**
 * Construct a server
 */
Server::Server() : m_socket(new SocketStream), m_running(false)
{

}


/**
 * Destruct the server.
 */
Server::~Server()
{
    close();
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

    m_socket->bind(address);
}

/**
 * Start an http server on given port.
 * 
 * @param const unsigned int & port
 * @return void
 */
void Server::listen(const unsigned int & port)
{
    m_port = port;

    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else
    if (::listen(m_socket->getId(), 5) < 0) 
    { 
        throw Exceptions::BadConnectionException("Could not listen on the given port");
    }
    #endif

    std::cout << "Server started on " << m_address << ":" << m_port << '\n';
    m_running = true;
}

/**
 * On data recieved event.
 * 
 * @param Http::Events::MessageRecievedHandler handler
 * @return void
 */
void Server::onConnection(Events::MessageRecievedHandler handler)
{
    #if IS_WINDOWS
    // @todo write windows specific implemention
    #else

    while (m_running) {

        int clientSocket = m_socket->waitForConnection();

        std::cout << "Accepted connection. Client id " << clientSocket << '\n'; 

        // Client Request
        Interfaces::SocketStreamInterface * stream = new SocketStream();
        Interfaces::ResponseInterface * response = new Response(stream);
        Interfaces::RequestInterface * request = new Request(response);
        Interfaces::ClientInterface * client = new Client(request);

        // Server Response
        Interfaces::ResponseInterface * serverResponse = handler(client);
        Interfaces::SocketStreamInterface * serverStream = serverResponse->getBody();

        ::send(clientSocket, serverStream->getContents().c_str(), std::strlen(serverStream->getContents().c_str()), 0);

        ::close(clientSocket);

        delete client;
    }

    ::close(m_socket->getId());

    #endif
}

/**
 * Close the http server.
 * 
 * @return void
 */
void Server::close()
{
    delete m_socket;
    m_running = false;
}
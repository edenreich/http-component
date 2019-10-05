#include "http/server.h"

#include "http/platform/check.h"

#include "http/client.h"
#include "http/request.h"
#include "http/response.h"
#include "http/server_socket.h"

#include "http/exceptions/bad_connection_exception.h"

#include <cstring>
#include <iostream>

using namespace Http;


/**
 * Construct a server
 */
Server::Server() : m_socket(new ServerSocket), m_running(false)
{
    m_socket->open();
}


/**
 * Destruct the server.
 */
Server::~Server()
{
    m_running = false;

    m_socket->close();

    delete m_socket;
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
 * @param const unsigned int port
 * @return void
 */
void Server::listen(const unsigned int port)
{
    m_port = port;
    
    m_socket->listen(port);

    std::cout << "Server started listening on " << m_address << ":" << m_port << '\n';

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
    do {

        Interfaces::ClientSocketInterface * clientSocket = m_socket->waitForConnection();

        std::cout << "Accepted connection. Client id " << clientSocket->getId() << '\n'; 

        // Client Request
        Interfaces::ResponseInterface * response = new Response(clientSocket);
        Interfaces::RequestInterface * request = new Request(response);
        Interfaces::ClientInterface * client = new Client(request);

        // Server Response
        Interfaces::ResponseInterface * serverResponse = handler(client);
        clientSocket = serverResponse->getBody();

        const std::string & content = clientSocket->getContents(); 

        clientSocket->send(content);
        clientSocket->close();

        delete client;

    } while((m_running));

    shutdown();
}

/**
 * Shutdown the http server.
 * 
 * @return void
 */
void Server::shutdown()
{
    delete this;
}
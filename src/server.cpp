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
    m_running = false;

    #if IS_WINDOWS
    ::closesocket(m_socket->getId());
    #else
    ::close(m_socket->getId());
    #endif

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
 * @param const unsigned int & port
 * @return void
 */
void Server::listen(const unsigned int & port)
{
    m_port = port;

    #if IS_WINDOWS
    int iResult = ::listen(m_socket->getId(), SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        throw Exceptions::BadConnectionException("Could not listen on the given port");
        closesocket(m_socket->getId());
        WSACleanup();
    }
    #else
    if (::listen(m_socket->getId(), 1) < 0) { 
        throw Exceptions::BadConnectionException("Could not listen on the given port");
    }
    #endif

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

        std::string content = serverStream->getContents(); 
        int bufferLength = static_cast<int>(std::strlen(content.c_str()));
        
        ::send(clientSocket, content.c_str(), bufferLength, 0);

        #if IS_WINDOWS
        ::closesocket(clientSocket);
        #else
        ::close(clientSocket);
        #endif

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
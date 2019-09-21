#include "http/server.h"
#include "http/exceptions/not_implemented_exception.h"

using namespace Http;


/**
 * Construct a server
 */
Server::Server()
{
    throw NotImplementedException();
}

/**
 * Bind the server to specific address.
 * 
 * @param const std::string & address
 * @return void
 */
void Server::bind(const std::string & address) const
{
    throw NotImplementedException();
}

/**
 * Start an http server on given port.
 * 
 * @param unsigned int port
 * @return void
 */
void Server::listen(unsigned int port) const
{
    throw NotImplementedException();
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
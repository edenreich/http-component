#ifndef BAD_CONNECTION_EXCEPTION_H
#define BAD_CONNECTION_EXCEPTION_H

#include <stdexcept>


class BadConnectionException : public std::exception
{

public:

    /**
     * Retrieve the reason.
     * 
     * @return char const *
     */
    char const * what() const throw() override { return "Could not connect to server."; }

};


#endif // BAD_CONNECTION_EXCEPTION_H
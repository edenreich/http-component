#ifndef BAD_CONNECTION_EXCEPTION_H
#define BAD_CONNECTION_EXCEPTION_H

#include <stdexcept>


class BadConnectionException : public std::exception
{

public:

    /**
     * Default constructor.
     */
    BadConnectionException() : m_message("Could not connect to server.") {}

    /**
     * Initialize a custom message.
     * 
     * @param char const * message
     */
    BadConnectionException(char const * message) noexcept : m_message(message) {}

    /**
     * Retrieve the reason.
     * 
     * @return char const *
     */
    char const * what() const throw() override { return m_message; }

private:

    /**
     * Store the custom message.
     * 
     * @var char const *
     */
    char const * m_message;

};


#endif // BAD_CONNECTION_EXCEPTION_H
#ifndef INVALID_CLIENT_SOCKET_EXCEPTION_H
#define INVALID_CLIENT_SOCKET_EXCEPTION_H

#include <stdexcept>


namespace Http {
    namespace Exceptions {

        class InvalidClientSocketException : public std::exception
        {

        public:

            /**
             * Default constructor.
             */
            InvalidClientSocketException() : m_message("Client socket is invalid.") {}

            /**
             * Initialize a custom message.
             * 
             * @param char const * message
             */
            InvalidClientSocketException(char const * message) noexcept : m_message(message) {}

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

    }
}


#endif // INVALID_CLIENT_SOCKET_EXCEPTION_H
#ifndef INVALID_MESSAGE_EXCEPTION_H
#define INVALID_MESSAGE_EXCEPTION_H

#include <stdexcept>


namespace Http {
    namespace Exceptions {

        class InvalidMessageException : public std::exception
        {

        public:

            /**
             * Default constructor.
             */
            InvalidMessageException() : m_message("Message is invalid.") {}

            /**
             * Initialize a custom message.
             * 
             * @param char const * message
             */
            InvalidMessageException(char const * message) noexcept : m_message(message) {}

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


#endif // INVALID_MESSAGE_EXCEPTION_H
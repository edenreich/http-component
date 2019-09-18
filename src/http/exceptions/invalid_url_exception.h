#ifndef INVALID_URL_EXCEPTION_H
#define INVALID_URL_EXCEPTION_H

#include <stdexcept>


class InvalidUrlException : public std::exception
{

public:

    /**
     * Retrieve the reason.
     * 
     * @return char const *
     */
    char const * what() const throw() override { return "Malformed url."; }

};


#endif // INVALID_URL_EXCEPTION_H
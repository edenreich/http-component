#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

#include <stdexcept>


class NotImplementedException : public std::exception
{

public:

    /**
     * Retrieve the reason.
     * 
     * @return char const *
     */
    char const * what() const throw() override { return "Pending implemention."; }

};


#endif // NOT_IMPLEMENTED_EXCEPTION_H
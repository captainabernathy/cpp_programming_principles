#ifndef IO_ERRORS_HPP
#define IO_ERRORS_HPP

#include <typeinfo> // for bad_cast

// class for reporting string cast errors
struct bad_from_string : std::bad_cast {

    const char *what() const throw()
    {
        return "bad cast from string";
    }
};

// class for reporting lexical cast errors
struct bad_lexical_cast : std::bad_cast {

    const char *what() const throw()
    {
        return "bad lexical cast";
    }
};

#endif

#ifndef MATRIX_ERROR_HPP
#define MATRIX_ERROR_HPP

#include <string> // for string
#include <exception> // for exception

namespace Numeric_lib {

// just a class for throwing Matrix-related errors... not sure entirely what
// they were going for anything more with this
struct Matrix_error : std::exception {
    std::string name;

    Matrix_error(const char *cstr)
        : name {cstr} { }

    Matrix_error(std::string str)
        : name {str} {  }

    const char *what() const throw()
    {
        return name.c_str();
    }
};

// error function that throws a Matrix_error with the c-string it was passed
inline void error(const char *cstr)
{
    throw Matrix_error(cstr);
}

}

#endif

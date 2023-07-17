#ifndef FROM_STRING_HPP
#define FROM_STRING_HPP

#include <string> // for string
#include <sstream> // for istringstream
#include <io_utils/io_errors.hpp> // for bad_from_string()

// function template that attempts to read an object of the type specified from
// the string passed to s
// NOTE: if s cannot be read as a type T, then the function throws a
// bad_from_string() exception
template<typename T>
T from_string(std::string const& s)
{
    std::istringstream is {s}; // initialize input string stream with s
    T t; // target type
    if (!(is >> t)) // read t from stream
        throw bad_from_string();
    return t;
}


#endif

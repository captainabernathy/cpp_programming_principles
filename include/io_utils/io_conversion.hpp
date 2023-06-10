#ifndef IO_CONVERSION_HPP
#define IO_CONVERSION_HPP

#include <sstream> // ostringstream, istringstream, stringstream
#include <string> // for string
#include <istream> // for ws
#include <io_utils/io_errors.hpp> // for bad_from_string, bad_lexical_cast


// function template takes an object of any type that has an operator << and
// returns that object as a string
template<typename T>
std::string to_string(T const& t)
{
    std::ostringstream os;
    os << t;  // write t into os
    return os.str();
}

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

// function template that attempts to interpret the object provided to src
// as an object of the type provided to Dest and returns the result
// NOTE: if the object provided to src, cannot be interpreted as the type
// provided to Dest, then the function throws a bad_lexical_cast() exception
template<typename Dest, typename Src>
Dest lexical_cast(Src src)
{
    std::stringstream interpreter;
    Dest dest;

    // write src into stream
    // read result from stream into dest
    // read remaining through eof into ws
    if (!(interpreter << src)
        || !(interpreter >> dest)
        || !(interpreter >> std::ws).eof())
        throw bad_lexical_cast();

    return dest;
}

#endif

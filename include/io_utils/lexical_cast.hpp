#ifndef LEXICAL_CAST_HPP
#define LEXICAL_CAST_HPP

#include <sstream> // for stringstream
#include <io_utils/io_errors.hpp>

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

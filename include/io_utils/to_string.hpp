#ifndef TO_STRING_HPP
#define TO_STRING_HPP

#include <string> // for string
#include <sstream> // for ostringstream

// function template takes an object of any type that has an operator << and
// returns that object as a string
template<typename T>
std::string to_string(T const& t)
{
    std::ostringstream os;
    os << t;  // write t into os
    return os.str();
}


#endif

#ifndef GUI_FACILITIES_HPP
#define GUI_FACILITIES_HPP

#include <string> // for string
#include <stdexcept> // for runtime_error()

// error functions for for graphics library

inline void error(std::string const& msg)
{
    throw std::runtime_error(msg);
}

inline void error(std::string s1, std::string s2)
{
    error(s1 + s2);
}

#endif

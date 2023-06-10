#include <io_utils/io_utils.hpp>

#include <string> // for string
#include <sstream> // for istringstream
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// function that converts the characters in s to a double and returns it
double str_to_double(std::string s)
{
    std::istringstream is {s}; // create a string stream to read from s
    double d;
    is >> d; // read contents of s into d

    if (!is) // stream in bad state
        error("double format error: ", s);

    return d;
}

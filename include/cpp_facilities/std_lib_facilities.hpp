#ifndef STD_LIB_FACILITIES_HPP
#define STD_LIB_FACILITIES_HPP

#include <iostream> // for cin
#include <sstream> // for ostringstream
#include <string> // for string
#include <stdexcept> // for runtime_error

// function simply waits for user input
inline void keep_window_open()
{
    std::cin.get();
}

// function promputs user to enter str before exiting
// NOTE: function will eventually exit after 10 failed attempts
inline void keep_window_open(std::string const& str)
{
    static int attempts = 10;

    while (--attempts)
    {
        std::cout << "Please enter " << str << " to exit: ";
        bool ex = true;

        for (std::string::const_iterator p = str.begin(); p != str.end(); p++)
            if (*p != std::cin.get())
            {
                ex = false;
                break;
            }

        if (ex)
            break;
    }
}

// function that throws a runtime_error that contains the string passed to msg
// NOTE: optionally, output msg to stderr by defining ERR_OUT
inline void error(std::string const& msg)
{
#ifdef ERR_OUT
    std::cerr << msg << '\n';
#endif
    throw std::runtime_error(msg);
}

inline void error(std::string s1, std::string s2)
{
    error(s1 + s2);
}

// function that reads integer passed to n into a string and forms an error
// message that concatenates the string passed to s1 with n, which subsequently
// forms the message of a runtime_error()
inline void error(std::string s1, int n)
{
    std::ostringstream oss;
    oss << n;
    error(s1, oss.str());
}

// function template that casts a variable of type Source to a variable of type
// Target and returns the result if the casting operation did not result in a
// loss of information... otherwise it calls error(), which throws a
// runtime_error
template <typename Target, typename Source>
Target narrow_cast(Source src)
{
    Target target = src;
    if ((Source)target != src)
        error("Invalid narrowing conversion");
    return target;
}

#endif

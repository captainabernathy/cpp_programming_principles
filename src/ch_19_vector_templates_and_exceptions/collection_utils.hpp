#ifndef COLLECTION_UTILS_HPP
#define COLLECTION_UTILS_HPP

#include <string> // for string
#include <iostream> // for cout

// function template that prints an index-able collection of type T
// prepended by string s... works for any index-able collection that has a size
// function
template<typename T>
void print(T const& t, std::string const& s)
{
    for (size_t i = 0; i < t.size(); i++)
        std::cout << s << "[" << i << "]: " << t[i] << '\n';
}

// function tempmlate that prints the first n elements of an index-able
// collection of type T prepended by string s
// NOTE: function does not provide any range checking
template<typename T>
void print(T const& t, size_t n, std::string const& s)
{
    for (size_t i = 0; i < n; i++)
        std::cout << s << "[" << i << "]: " << t[i] << '\n';
}

#endif

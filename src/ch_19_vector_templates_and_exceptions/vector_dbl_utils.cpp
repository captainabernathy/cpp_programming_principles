#include "vector_dbl_utils.hpp"

#include <iostream> // for cout
#include <string> // for string

// function that outputs the contents of vector v prepended by string s
void print_vec(vector const& v, std::string const& s)
{
    for (size_t i = 0; i < v.size(); i++)
        std::cout << s << "[" << i << "]: " << v[i] << '\n';
}

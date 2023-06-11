#include "vector_dbl_utils.hpp"

#include <iostream> // for cout

// outputs the contents of the vector it receives and prepends each
// with the string it receives
void print_vector(vector const& v, std::string const& s)
{
    // loop over each vector and output each element prepended by s
    for (size_t i = 0; i < v.size(); i++)
// not defined when the member access operator is supported
#ifndef GET_AND_SET
        std::cout << s << ": " << v[i] << '\n';
#else
        std::cout << s << ": " << v.get(i) << '\n';
#endif
}

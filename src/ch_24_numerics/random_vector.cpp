#include "ch_24_utils.hpp"

#include <numeric_utils/linear_equations_types.hpp> // for Vector
#include <cstdlib> // for rand(), RAND_MAX

// initializes a Vector of n random doubles
Vector random_vector(size_t n)
{
    Vector v(n); // create Vector

    // initialize elements
    for (size_t i = 0; i < n; i++)
        v(i) = 1.0 * n * rand() / RAND_MAX;

    return v;
}

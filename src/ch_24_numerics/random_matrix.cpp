#include "ch_24_utils.hpp"

#include <numeric_utils/linear_equations_types.hpp> // for Matrix

// initializes an nxn Matrix of random doubles
Matrix random_matrix(size_t n)
{
    Matrix m(n, n); // create Matrix

    // initialize rows
    for (size_t i = 0; i < n; i++)
        m[i] = random_vector(n);

    return m;
}

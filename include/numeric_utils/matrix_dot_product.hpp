#ifndef MATRIX_DOT_PRODUCT_HPP
#define MATRIX_DOT_PRODUCT_HPP

#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_error.hpp> // for error()

namespace Numeric_lib {

// computes the dot (inner) product of a and b (as the sum of a[i] * b[i]) and
// returns the result
template<typename T>
T dot_product(Matrix<T> const& a, Matrix<T> const& b)
{
    const size_t sz = a.size();

    if (sz != b.size()) // no computation if sizes don't match
        error("wrong sizes for dot product");

    T sum = 0; // start at 0

    // loop over elements
    for (size_t i = 0; i < sz; i++)
        sum += a[i] * b[i]; // accumulate result

    return sum;
}

}

#endif

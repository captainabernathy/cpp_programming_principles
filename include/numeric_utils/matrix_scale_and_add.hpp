#ifndef MATRIX_SCALE_AND_ADD_HPP
#define MATRIX_SCALE_AND_ADD_HPP

#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_error.hpp> // for error()

namespace Numeric_lib {

// fused multiply add
// returns a Matrix whose elements are equal to the sum of the product of an
// element in a and c plus an element in b corresponding to the position of a
template<typename T>
Matrix<T> scale_and_add(Matrix<T> const& a, T c, Matrix<T> const& b)
{
    const size_t sz = a.size();

    if (sz != b.size()) // no computation if sizes don't match
        error("wrong sizes for scale_and_add()");

    Matrix<T> res {sz}; // allocate and initialize a Matrix for the result

    // loop over elements and perform fused multiply add
    for (size_t i = 0; i < sz; i++)
        res[i] += a[i] * c + b[i];

    return res.xfer(); // transfer ownership and return result
}

// fused multiply add
// returns a Matrix whose elements are equal to the sum of the product of an
// element in a and c plus an element in b corresponding to the position of a
template<typename T, size_t N>
Matrix<T, N - 1> scale_and_add(Matrix<T, N> const& a,
                               const Matrix<T, N - 1> c,
                               Matrix<T, N - 1> const& b)
{
    const size_t sz = a.size();

    if (sz != b.size()) // no computation if sizes don't match
        error("wrong sizes for scale_and_add()");

    Matrix<T> res {sz}; // allocate and initialize a Matrix for the result

    // loop over elements and perform fused multiply add
    for (size_t i = 0; i < sz; i++)
        res[i] += a[i] * c + b[i];

    return res.xfer(); // transfer ownership and return result
}

}

#endif

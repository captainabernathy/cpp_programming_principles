#ifndef MATRIX_OPERATORS_HPP
#define MATRIX_OPERATORS_HPP

#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_dot_product.hpp> // for dot_product<>()
#include <numeric_utils/matrix_error.hpp> // for error()

namespace Numeric_lib {

// adds c to each of m's elements and returns the resulting Matrix
// NOTE: m must have a += operator
template<typename T, size_t D>
Matrix<T, D> operator+(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r += c;
}

// adds the corresponding elements of two Matrix-s of the same type and number
// of dimensions
template<typename T, size_t D>
Matrix<T, D> operator+(Matrix<T, D> const& m, Matrix<T, D> const& n)
{
    const size_t sz = m.size();

    if (sz != n.size())
        error("matrix addition: dimension mismatch");

    Matrix<T, D> res {m}; // copy initialize results Matrix with m
    T *tres = res.data(); // extract results Matrix's data
    T *tn = n.data(); // extract Matrix n's data

    // loop over elements
    for (size_t i = 0; i < sz; i++)
        tres[i] += tn[i]; // perform addition of corresponding elements
 
    return res;
}

// multiplies c by each of m's elements and returns the resulting Matrix
// NOTE: m must have a *= operator
template<typename T, size_t D>
Matrix<T, D> operator*(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r *= c;
}

// performs matrix-vector multiplication... b/t a Matrix of 2 dimensions and
// a Matrix (vector) of 1 dimension of the same type... and returns a vector
// that contains the result
template<typename T>
Matrix<T, 1> operator*(Matrix<T, 2> const& m, Matrix<T, 1> const& u)
{
    const size_t n = m.dim1();

    if (m.dim2() != u.dim1()) // no computation if sizes are invalid
        error("matrix-vector multiplication: dimension mismatch");

    Matrix<T, 1> v {n}; // initialize results vector

    // loop over elements and use dot_product<>() to compute value of each
    // element in the results vector
    for (size_t i = 0; i < n; i++)
        v[i] = dot_product(m[i], u);

    return v;
}

// subtracts c from each of m's elements and returns the resulting Matrix
// NOTE: m must have a -= operator
template<typename T, size_t D>
Matrix<T, D> operator-(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r -= c;
}

// divides each of m's elements by c and returns the resulting Matrix
// NOTE: m must have a /= operator
template<typename T, size_t D>
Matrix<T, D> operator/(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r /= c;
}

// performs the modulus operation on each of m's elements by c and returns the
// resulting Matrix
// NOTE: m must have a %= operator
template<typename T, size_t D>
Matrix<T, D> operator%(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r %= c;
}

// performs the bitwise OR operation on each of m's elements by c and returns
// the resulting Matrix
// NOTE: m must have a |= operator
template<typename T, size_t D>
Matrix<T, D> operator|(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r |= c;
}

// performs the XOR operation on each of m's elements by c and returns the
// resulting Matrix
// NOTE: m must have a ^= operator
template<typename T, size_t D>
Matrix<T, D> operator^(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r ^= c;
}

// performs the bitwise AND operation on each of m's elements by c and returns
// the resulting Matrix
// NOTE: m must have a &= operator
template<typename T, size_t D>
Matrix<T, D> operator&(Matrix<T, D> const& m, T const& c)
{
    Matrix<T, D> r {m}; // copy initialize with m
    return r &= c;
}

}

#endif

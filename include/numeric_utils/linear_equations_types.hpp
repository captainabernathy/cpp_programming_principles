#ifndef LINEAR_EQUATIONS_TYPES_HPP
#define LINEAR_EQUATIONS_TYPES_HPP

#include <numeric_utils/matrix_t2.hpp> // for Matrix<T,2>
#include <numeric_utils/matrix_t1.hpp> // for Matrix<T,1>

// a "Matrix" is a two-dimensional Matrix of doubles
// typedef Numeric_lib::Matrix<double, 2> Matrix;
using Matrix = Numeric_lib::Matrix<double, 2>; // same as above

// a "Vector" is a one-dimensional Matrix of doubles
// typedef Numeric_lib::Matrix<double, 1> Vector;
using Vector = Numeric_lib::Matrix<double, 1>; // same as above

#endif

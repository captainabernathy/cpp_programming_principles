#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef> // for size_t

namespace Numeric_lib {

// Matrix Features:
//      ( ) performs multidimensional subscripting
//      [ ] performs c-style slicing: gives an N-1 dimensional matrix from an
//          N-dimensional one
//      row( ) is equivalent to [ ]
//      column( ) is not (yet) implemented bc it requires strides
//      = provides copy semantics
//      ( ) and [ ] are range-checked
//      slice( ) provides access to subranges
//      scaling operations (+=, *=, -=, /=, %=, etc)
//      fused vector operations: res[i] = a[i] * c + b[i]
//      dot (inner) product: res = sum of a[i] * b[i]

// NOTE: this template serves only as a prop for its specializations
template<typename T = double, size_t D = 1>
class Matrix {
    Matrix() = delete;
};

}

#endif

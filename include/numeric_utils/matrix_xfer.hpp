#ifndef MATRIX_XFER_HPP
#define MATRIX_XFER_HPP

#include <numeric_utils/matrix.hpp> // for Matrix<>

namespace Numeric_lib {

// returns a (descriptor to) a Matrix that has been given ownership of a
template<typename T, size_t N>
Matrix<T, N> xfer(Matrix<T, N>& a)
{
    return a.xfer();
}

}

#endif

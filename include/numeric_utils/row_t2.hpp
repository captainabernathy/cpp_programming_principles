#ifndef ROW_T2_HPP
#define ROW_T2_HPP

#include <numeric_utils/apply_operations.hpp> // for Assign<>
#include <numeric_utils/row.hpp> // for Row<>
// #include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_t2.hpp> // for Matrix<T,2>

namespace Numeric_lib {

// Row<T,2> represents a two-dimensional Row of type T... that can be
// used to represent a row of a two-dimensional Matrix
template<typename T>
class Row<T, 2> : public Matrix<T, 2> {
public:
    // constructs a (descriptor to) Row from a pointer and two dimensions...
    // owned by someone else
    Row(size_t n1, size_t n2, T *p)
        : Matrix<T, 2> {n1, n2, p} { }

    // assigns c to each of the elements in this Row and returns a reference
    // to a two-dimensional Matrix that contains the results
    Matrix<T, 2>& operator=(T const& c)
    {
        this->base_apply(Assign<T>(), c);
        return *this;
    }

    // assigns a to this Row and returns a reference to a two-dimensional
    // Matrix that contains the results
    Matrix<T, 2>& operator=(Matrix<T, 2> const& a)
    {
        return *static_cast<Matrix<T, 2> *>(this) = a;
    }
};

}

#endif

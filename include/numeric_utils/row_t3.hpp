#ifndef ROW_T3_HPP
#define ROW_T3_HPP

#include <numeric_utils/apply_operations.hpp> // for Assign<>
#include <numeric_utils/row.hpp> // for Row<>
// #include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_t3.hpp> // for Matrix<T,3>

namespace Numeric_lib {

// Row<T,3> represents a three-dimensional Row of type T... that can be
// used to represent a "row" of a three-dimensional Matrix
template<typename T>
class Row<T, 3> : public Matrix<T, 3> {
public:
    // constructs a (descriptor to) Row from a pointer and three dimensions...
    // owned by someone else
    Row(size_t n1, size_t n2, size_t n3, T *p)
        : Matrix<T, 3> {n1, n2, n3, p} { }

    // assigns c to each of the elements in this Row and returns a reference
    // to a three-dimensional Matrix that contains the results
    Matrix<T, 3>& operator=(T const& c)
    {
        this->base_apply(Assign<T>(), c);
        return *this;
    }

    // assigns a to this Row and returns a reference to a three-dimensional
    // Matrix that contains the results
    Matrix<T, 3>& operator=(Matrix<T,3> const& a)
    {
        return *static_cast<Matrix<T, 3> *>(this) = a;
    }
};

}

#endif

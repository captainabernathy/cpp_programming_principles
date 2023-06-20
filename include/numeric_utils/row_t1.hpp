#ifndef ROW_T1_HPP
#define ROW_T1_HPP

#include <numeric_utils/apply_operations.hpp> // for Assign<>
#include <numeric_utils/row.hpp> // for Row<>
// #include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_t1.hpp> // for Matrix<T,1>

namespace Numeric_lib {

// Row<T,1> represents a single Row of type T... that can be used to represent
// a row of a one-dimensional Matrix
template<typename T>
class Row<T, 1> : public Matrix<T, 1> {
public:
    // constructs a (descriptor to) Row from a pointer and a dimension...
    // owned by someone else
    Row(size_t n, T *p)
        : Matrix<T, 1> {n, p} { }

    // assigns c to each of the elements in this Row and returns a reference
    // to a one-dimensional Matrix that contains the results
    Matrix<T, 1>& operator=(T const& c)
    {
        this->base_apply(Assign<T>(), c);
        return *this;
    }

    // assigns a to this Row and returns a reference to a one-dimensional
    // Matrix that contains the results
    Matrix<T, 1>& operator=(Matrix<T, 1> const& a)
    {
        return *static_cast<Matrix<T, 1> *>(this) = a;
    }
};

}

#endif

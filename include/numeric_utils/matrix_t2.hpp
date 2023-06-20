#ifndef MATRIX_T2_HPP
#define MATRIX_T2_HPP

#include <algorithm> // for swap()
#include <numeric_utils/matrix_error.hpp> // for error()
#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_base.hpp> // for Matrix_base<>
#include <numeric_utils/matrix_t1.hpp> // for Matrix<T,1>
#include <numeric_utils/row.hpp> // for Row<>
#include <numeric_utils/row_t1.hpp> // for Row<T,1>
#include <numeric_utils/row_t2.hpp> // for Row<T,2>
#include <numeric_utils/apply_operations.hpp> // for Assign<>, Add_assign<>,
                                              // Mul_assign<>, Minux_assign<>,
                                              // Div_assign<>, Mod_assign<>,
                                              // Or_assign<>, Xor_assign<>,
                                              // And_assign<>, Not<>,
                                              // Unary_minus<>, Complement<>
  
namespace Numeric_lib {

// Matrix<T, 2> represents a two-dimensional Matrix of type T
template<typename T>
class Matrix<T, 2> : public Matrix_base<T> {
    // NOTE: a 2D matrix with rows of length d1 and columns of height d2 has
    // d1 * d2 elements
    // rows
    const size_t d1; // number of elements in this Matrix's first dimension
    // columns
    const size_t d2; // number of elements in this Matrix's second dimension

protected:
    // receives a pointer and two dimensions... owned by someone else
    // used typically by/for a Row
    Matrix(size_t n1, size_t n2, T *p)
        : Matrix_base<T> {n1 * n2, p}, // initializes descriptor
          d1 {n1},
          d2 {n2} { }

public:
    // receives two dimensions only... requires allocation... owned by us
    Matrix(size_t n1, size_t n2)
        : Matrix_base<T> {n1 * n2}, // allocates and initializes
          d1 {n1},
          d2 {n2} { }

    // converts a 2D Row to a Matrix
    // receives a reference to a 2D Row... owned by someone else
    Matrix(Row<T, 2>& a)
        : Matrix_base<T> {a.dim1() * a.dim2(), a.p}, // initializes descriptor
          d1 {a.dim1()},
          d2 {a.dim2()} { }

    // copy constructor... lets base do the copy
    Matrix(Matrix const& a)
        : Matrix_base<T> {a.size(), nullptr}, // initializes descriptor
          d1 {a.d1},
          d2 {a.d2}
    {
        this->base_copy(a); // copies elements and establishes our ownership
    }

    // converts an n1 by n2, 2D array of type T to a Matrix
    // deduces n1, n2, and T... Matrix_base allocates T[n1*n2]... owned by
    // us... this Matrix does the copy
    template<size_t n1, size_t n2>
    Matrix(T const(&a)[n1][n2])
        : Matrix_base<T> {n1 * n2}, // allocates and initializes
          d1 {n1},
          d2 {n2}
    {
        // loop over a's dimensions and copy its elements
        // NOTE: i * n2 + j = linear offset into 2D array
        for (size_t i = 0; i < n1; i++)
            for (size_t j = 0; j < n2; j++)
                this->elems[i * n2 + j] = a[i][j];
    }

    // constructs a new Matrix with elements that are functions of a's elements
    //
    // Matrix_base alloates T[n]... owned by us.. this Matrix does the copy
    //
    // NOTE: f will not modify a, unless it has been programmed to do so...
    // a typical signature for f would be T f(T const& t)
    template<typename F>
    Matrix(Matrix const& a, F f)
        : Matrix_base<T> {a.size()}, // allocates and initializes
          d1 {a.d1},
          d2 {a.d2}
    {
        // loop over elements and copy the result of applying f() to each
        for (size_t i = 0; i < this->sz; i++)
            this->elems[i] = f(a.elems[i]);
    }

    // constructs a new Matrix with elements that are functions of a's elements
    // using t1 as an argument
    //
    // Matrix_base alloates T[n]... owned by us.. this Matrix does the copy
    //
    // NOTE: f will not modify a, unless it has been programmed to do so...
    // a typical signature for f would be T f(T const& t, Arg const& t1)
    template<typename F, typename Arg>
    Matrix(Matrix const& a, F f, Arg const& t1)
        : Matrix_base<T> {a.size()}, // allocate and initialize
          d1 {a.d1},
          d2 {a.d2}
    {
        // loop over elements and copy the result of applying f() to each
        // along with t1
        for (size_t i = 0; i < this->sz; i++)
            this->elems[i] = f(a.elems[i], t1);
    }

    // copy assignment operator...
    // lets the base do the copy
    Matrix& operator=(Matrix const& a)
    {
        // if (d1 != a.d1 || d2 != a.d2)
        if (!(d1 == a.d1 && d2 == a.d2)) // no copy if dimensions don't match
            error("length error in 2D =");

        this->base_assign(a); // base copies a's elements to this Matrix
        return *this;
    }

    // destructor
    ~Matrix() { }

    // returns the number elements in this Matrix's first dimension
    size_t dim1() const
    {
        return d1; // number of elements in a row
    }

    // returns the number of elements in this Matrix's second dimension
    size_t dim2() const
    {
        return d2; // number of elements in a column
    }

    // returns a (descriptor to) a Matrix that has been given ownership of
    // this Matrix's data
    Matrix xfer()
    {
        Matrix x {dim1(), dim2(), this->data()}; // make a descriptor
        this->base_xfer(x); // transfer (temporary) ownership of x
        return x; // NOTE: x's own and xfer members are set
    }

    // throws and error if n1 is not within the range [0,d1-1]
    // or if n2 is not within the range of [0,d2-1]
    void range_check(size_t n1, size_t n2) const
    {
        // n1 cannot be negative nor greater than or equal to d1...
        // for indexing n1 can be at most d1 - 1
        if (long(n1) < 0 || d1 <= n1)
            error("2D range error: dimension 1");

        // n2 cannot be negative nor greater than or equal to d2...
        // for indexing n2 can be at most d2 - 1
        if (long(n2) < 0 || d2 <= n2)
            error("2D range error: dimension 2");
    }

    // subscripting... a(i,j) == a[i][j]
    // returns a reference to the element at the position of row n1, and
    // column n2 in this Matrix
    T& operator()(size_t n1, size_t n2)
    {
        range_check(n1, n2); // throws if either n1 or n2 is invalid
        return this->elems[n1 * d2 + n2];
    }

    // returns a reference to the element at the position of row n1, and
    // column n2 in this Matrix... for a constant Matrix
    T const& operator()(size_t n1, size_t n2) const
    {
        range_check(n1, n2); // throws if either n1 or n2 is invalid
        return this->elems[n1 * d2 + n2];
    }

    // slicing/indexing...
    // returns (the 1D) row n of this matrix
    Row<T, 1> operator[](size_t n)
    {
        return row(n);
    }

    // returns (the 1D) row n of this matrix... for a constant Matrix
    const Row<T, 1> operator[](size_t n) const
    {
        return row(n);
    }

    // returns (the 1D) row n of this matrix
    Row<T, 1> row(size_t n)
    {
        range_check(n, 0); // throws if n is invalid

        // d2 = number of elements in the row (all columns)
        // n * d2 = (offset of) the start of row n
        return Row<T, 1> {d2, &this->elems[n * d2]};
    }
 
    // returns (the 1D) row n of this matrix... for a constant Matrix
    const Row<T, 1> row(size_t n) const
    {
        range_check(n, 0); // throws if n is invalid

        // d2 = number of elements in the row (all columns)
        // n * d2 = (offset of) the start of row n
        return Row<T, 1> {d2, &this->elems[n * d2]};
    }

    // returns a 2D Row that consists of the rows of this Matrix from row
    // n to row d1 - 1 (the last row)
    Row<T, 2> slice(size_t n)
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end

        // d1 - n = number of rows in the slice
        // d2 = all columns
        // n * d2 = (offset of) the first element of row n (start of slice)
        return Row<T, 2> {d1 - n, d2, this->elems + n * d2};
    }

    // returns a 2D Row that consists of the rows of this Matrix from row
    // n to row d1 - 1 (the last row)... for a constant Matrix
    const Row<T, 2> slice(size_t n) const
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end

        // d1 - n = number of rows in the slice
        // d2 = all columns
        // n * d2 = (offset of) the first element of row n (start of slice)
        return Row<T, 2> {d1 - n, d2, this->elems + n * d2};
    }

    // returns a 2D Row that consists of the rows of this Matrix from row
    // n up to row m
    Row<T, 2> slice(size_t n, size_t m)
    {
        if (long(n) < 0)
            n = 0; // the beginning
        
        if (d1 < m)
            m = d1; // one beyond the end

        // m - n = number of rows in the slice
        // d2 = all columns
        // n * d2 = (offset of) the first element of row n (start of slice)
        return Row<T, 2> {m - n, d2, this->elems + n * d2};
    }

    // returns a 2D Row that consists of the rows of this Matrix from row
    // n up to row m... for a constant Matrix
    const Row<T, 2> slice(size_t n, size_t m) const
    {
        if (long(n) < 0)
            n = 0; // the beginning
        
        if (d1 < m)
            m = d1; // one beyond the end

        // m - n = number of rows in the slice
        // d2 = all columns
        // n * d2 = (offset of) the first element of row n (start of slice)
        return Row<T, 2> {m - n, d2, this->elems + n * d2};
    }

    // NOTE: requires strides and operations on columns
    // Column<T, 1> column(size_t n); // NOT IMPLEMENTED

    // element-wise operations:
    // applies the function f to each of this Matrix's elements and returns
    // a reference to the result
    template<typename F>
    Matrix& apply(F f)
    {
        this->base_apply(f);
        return *this;
    }

    // applies the function f to each of this Matrix's elements using c as
    // an additional argument to the call and returns a reference to the result
    template<typename F>
    Matrix& apply(F f, T const& c)
    {
        this->base_apply(f, c);
        return *this;
    }

    // assigns c to each of this Matrix's elements and returns a reference to
    // the result
    Matrix& operator=(T const& c)
    {
        this->base_apply(Assign<T>(), c);
        return *this;
    }

    // adds c to each of this Matrix's elements and returns a reference to the
    // result
    Matrix& operator+=(T const& c)
    {
        this->base_apply(Add_assign<T>(), c);
        return *this;
    }

    // multiplies each of this Matrix's elements by c and returns a reference
    // to the result
    Matrix& operator*=(T const& c)
    {
        this->base_apply(Mul_assign<T>(), c);
        return *this;
    }

    // subtracts c from each of this Matrix's elements and returns a reference
    // to the result
    Matrix& operator-=(T const& c)
    {
        this->base_apply(Minus_assign<T>(), c);
        return *this;
    }

    // divides each of this Matrix's elements by c and returns a reference to
    // the result
    Matrix& operator/=(T const& c)
    {
        this->base_apply(Div_assign<T>(), c);
        return *this;
    }

    // performs the modulus operation on each of this Matrix's elements by c
    // and returns a reference to the result
    Matrix& operator%=(T const& c)
    {
        this->base_apply(Mod_assign<T>(), c);
        return *this;
    }

    // performs the bitwise OR operation on each of this Matrix's elements by c
    // and returns a reference to the result
    Matrix& operator|=(T const& c)
    {
        this->base_apply(Or_assign<T>(), c);
        return *this;
    }

    // performs the XOR operation on each of this Matrix's elements by c and
    // returns a reference to the result
    Matrix& operator^=(T const& c)
    {
        this->base_apply(Xor_assign<T>(), c);
        return *this;
    }

    // performs the bitwise AND operation on each of this Matrix's elements by
    // c and returns a reference to the result
    Matrix& operator&=(T const& c)
    {
        this->base_apply(And_assign<T>(), c);
        return *this;
    }

    // returns (a descriptor to) a Matrix whose elements are equal to applying
    // the logical NOT operation to this Matrix's elements
    Matrix operator!()
    {
        return xfer({*this, Not<T>()});
    }

    // returns (a descriptor to) a Matrix whose elements are equal to the
    // opposite of this Matrix's elements (unary minus)
    Matrix operator-()
    {
        return xfer({*this, Unary_minus<T>()});
    }

    // returns (a descriptor to) a Matrix whose elements are equal to applying
    // the bitwise complement (NOT) operation to this Matrix's elements
    Matrix operator~()
    {
        return xfer({*this, Complement<T>()});
    }

    // returns (a descriptor to) a Matrix whose elements are equal to applying
    // the function f to each of this Matrix's elements
    template<typename F>
    Matrix apply_new(F f)
    {
        return xfer({*this, f});
    }

    // swaps row i and row j of this Matrix
    // uses a row's worth of memory for better run-time performance
    void swap_rows(size_t i, size_t j)
    {
        if (i == j)
            return;

        Matrix<T, 1> tmp = (*this)[i];
        (*this)[i] = (*this)[j];
        (*this)[j] = tmp;

        // pairwise-swap
        // size_t mmax = (*this)[i].size();
        // for (size_t ii = 0; ii < mmax; ii++)
        //     std::swap((*this)(i, ii), (*this)(j, ii));
    }
};

}

#endif

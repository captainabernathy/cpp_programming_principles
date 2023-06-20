#ifndef MATRIX_T1_HPP
#define MATRIX_T1_HPP

#include <algorithm> // for swap()
#include <numeric_utils/matrix_error.hpp> // for error()
#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_base.hpp> // for Matrix_base<>
#include <numeric_utils/row.hpp> // for /Row<>
#include <numeric_utils/row_t1.hpp> // for Row<T,1>
#include <numeric_utils/apply_operations.hpp> // for Assign<>, Add_assign<>,
                                              // Mul_assign<>, Minux_assign<>,
                                              // Div_assign<>, Mod_assign<>,
                                              // Or_assign<>, Xor_assign<>,
                                              // And_assign<>, Not<>,
                                              // Unary_minus<>, Complement<>
 
namespace Numeric_lib {

// Matrix<T, 1> represents a one-dimensional Matrix of type T
template<typename T>
class Matrix<T, 1> : public Matrix_base<T> {
    const size_t d1; // number of elements in this Matrix's only dimension

protected:
    // receives a pointer and a dimension... owned by someone else
    // used typically by/for a Row
    Matrix(size_t n1, T *p)
        : Matrix_base<T> {n1, p}, // initializes descriptor
          d1 {n1} { }

public:
    // receives only a size... requires allocation... owned by us
    Matrix(size_t n1)
        : Matrix_base<T> {n1}, // allocates and initializes
          d1 {n1} { }

    // converts a 1D row to a Matrix
    // receives a reference to a (1D) Row... owned by someone else
    Matrix(Row<T, 1>& a)
        : Matrix_base<T> {a.dim1(), a.p}, // initializes descriptor
          d1 {a.dim1()} { }

    // copy constructor
    // lets the base do the copy
    Matrix(Matrix const& a)
        : Matrix_base<T> {a.size(), nullptr}, // initializes descriptor
          d1 {a.d1}
    {
        this->base_copy(a); // copies and establishs our ownership
    }

    // converts an n element array of type T to a Matrix
    // deduces n and T, Matrix_base allocates T[n]... owned by us... this
    // Matrix does the copy
    template<size_t n>
    Matrix(T const(&a)[n])
        : Matrix_base<T> {n}, // allocates and initializes
          d1 {n}
    {
        for (size_t i = 0; i < n; i++) // loop over elements and...
            this->elems[i] = a[i]; // copy each one
    }

    // converts n elements of the type p points to, to a Matrix
    // Matrix_base allocates T[n]... owned by us... this Matrix does the copy
    Matrix(const T *p, size_t n)
        : Matrix_base<T> {n}, // allocates and initializes
          d1 {n}
    {
        for (size_t i = 0; i < n; i++) // loop over elements and...
            this->elems[i] = p[i]; // copy each one
    }

    // constructs a new Matrix with elements that are functions of a's elements
    //
    // Matrix_base alloates T[n]... owned by us.. this Matrix does the copy
    //
    // NOTE: f will not modify a, unless it has been programmed to do so...
    // a typical signature for f would be: T f(T const& t)
    template<typename F>
    Matrix(Matrix const& a, F f)
        : Matrix_base<T> {a.size()}, // allocate and initialize
          d1 {a.d1}
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
    // a typical signature for f would be: T f(T const& t, Arg const& t1)
    template<typename F, typename Arg>
    Matrix(Matrix const& a, F f, Arg const& t1)
        : Matrix_base<T> {a.size()}, // allocate and initialize
          d1 {a.d1}
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
        if (d1 != a.d1) // no copy if sizs aren't the same
            error("length error in 1D=");

        this->base_assign(a); // base copies a's elements to this Matrix
        return *this;
    }

    // destructor
    ~Matrix() { }

    // returns the number of elements in this Matrix's only dimension
    size_t dim1() const
    {
        return d1; // number of elements in a row
    }

    // returns a (descriptor to) a Matrix that has been given ownership of
    // this Matrix's data
    Matrix xfer()
    {
        // make a Matrix to move this Matrix's elements out of a scope
        Matrix x {dim1(), this->data()}; // make a descriptor to our data
        this->base_xfer(x); // transfer (temporary) ownership to x
        return x; // NOTE: x's own and xfer members are set
    }

    // throws an error if n1 is not within the range [0,d1-1]
    void range_check(size_t n1) const
    {
        // n1 cannot be negative nor greater than or equal to d1...
        // for indexing n1 can be at most d1 - 1
        if (long(n1) < 0 || d1 <= n1)
            error("1D range error: dimension 1");
    }

    // subscripting... a(n) == a[n]
    // returns a reference to the element at position n1 in this Matrix
    T& operator()(size_t n1)
    {
        range_check(n1); // throws if n1 is invalid
        return this->elems[n1];
    }

    // subscripting for a constant Matrix
    T const& operator()(size_t n1) const
    {
        range_check(n1); // throws if n1 is invalid
        return this->elems[n1];
    }

    // slicing/indexing (same as subscripting for 1D matrices)
    // returns a reference to the element at position n in this Matrix
    T& operator[](size_t n)
    {
        return row(n);
    }

    // slicling/indexing... for a constant Matrix
    T const& operator[](size_t n) const
    {
        return row(n);
    }

    // returns a reference to the element at position n in this Matrix
    T& row(size_t n)
    {
        range_check(n); // throws if n is invalid
        return this->elems[n];
    }

    // returns a reference to the element at position n in this Matrix...
    // for a constant Matrix
    T const& row(size_t n) const
    {
        range_check(n); // throws if n is invalid
        return this->elems[n];
    }

    // returns returns a Row of elements from this Matrix that consists of
    // elements from a[n] to a[d1 - 1] (the end)
    Row<T, 1> slice(size_t n)
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end
        
        // d1 - n = number of elements in the slice
        // elems + n = (offset of) the first element (start of) the slice
        return Row<T, 1> {d1 - n, this->elems + n};
    }

    // returns returns a Row of elements from this Matrix that consists of
    // elements from a[n] to a[d1 - 1] (the end)... for a const Matrix
    const Row<T, 1> slice(size_t n) const
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end

        // d1 - n = number of elements in the slice
        // elems + n = (offset of) the first element (start of) the slice
        return Row<T, 1> {d1 - n, this->elems + n};
    }

    // returns a Row of m elements from this Matrix starting from a[n]
    Row<T, 1> slice(size_t n, size_t m)
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end

        if (long(m) < 0)
            m = 0; // the beginning
        else if (d1 < n + m) // true when there aren't m elements beyond a[n]
            m = d1 - n; // makes slice run from a[n] to the end

        // m = number of elements in the slice
        // elems + n = (offset of) the first element (start of) the slice
        return Row<T, 1> {m, this->elems + n};
    }

    // returns a Row of m elements from this Matrix starting from a[n]...
    // for a const Matrix
    const Row<T, 1> slice(size_t n, size_t m) const
    {
        if (long(n) < 0)
            n = 0; // the beginning
        else if (d1 < n)
            n = d1; // one beyond the end

        if (long(m) < 0)
            m = 0; // the beginning
        else if (d1 < n + m) // true when there aren't m elements beyond a[n]
            m = d1 - n; // makes slice run from a[n] to the end

        // m = number of elements in the slice
        // elems + n = (offset of) the first element (start of) the slice
        return Row<T, 1> {m, this->elems + n};
    }

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

    // NOTE: since this Matrix only has a single dimension, this method simply
    // swaps the elements at positions i and j
    void swap_rows(size_t i, size_t j)
    {
        if (i == j)
            return;

        // NOTE: indexing operations are written to check range
    
        // uses a row's worth of memory for better run-time performance...
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

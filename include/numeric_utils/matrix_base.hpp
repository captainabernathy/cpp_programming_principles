#ifndef MATRIX_BASE_HPP
#define MATRIX_BASE_HPP

#include <numeric_utils/matrix_error.hpp> // for error()

namespace Numeric_lib {

// Matrix_base represents the common part of the Matrix class
template<typename T>
class Matrix_base {
protected:
    T *elems; // this Matrix_base's elements
    const size_t sz; // total number of elements in this Matrix_base
    
    // NOTE: the mutable specifier permits modification of a class member even
    // if the object that contains it is declared const
    mutable bool owns; // this Matrix_base's ownership state
    mutable bool xfer; // this Matrix_base's transfer state

public:
    // Matrix of n elements, dynamically allocated, default initialized, and
    // owned by this Matrix_base
    Matrix_base(size_t n)
        : sz {n}, // number of elements to allocate
          owns {true},
          xfer {false}
    {
        if (long(sz) < 0)
            error("invalid value of n provided to Matrix constructor");

        elems = new T[n]();
    }

    // descriptor for a Matrix of n elements, containing the data p points to,
    // owned by someone else
    Matrix_base(size_t n, T *p)
        : elems {p}, // associate data
          sz {n}, // n used for book keeping... not for allocation
          owns {false},
          xfer {false} {  }

    // destructor... deallocates elements if they were allocated by this
    // Matrix_base
    ~Matrix_base()
    {
        if (owns)
            delete []elems;
    }

    // read-write, access to this Matrix_base's elements (raw pointer)
    T *data()
    {
        return elems;
    }

    // read-only access to this Matrix_base's elements...
    // for a constant Matrix_base
    const T *data() const
    {
        return elems;
    }

    // returns the number of elements in this Matrix_base
    size_t size() const
    {
        return sz;
    }

    // copies the elements of Matrix_base a to the elements of this Matrix_base
    void copy_elements(Matrix_base const& a)
    {
        if (sz != a.sz) // no copy if sizes aren't the same
            error("copy_elements()");

        for (size_t i = 0; i < sz; i++) // loop over elements
            elems[i] = a.elems[i]; // copy a's elements
    }

    // copies the elements of Matrix_base a to the elements of this Matrix_base
    void base_assign(Matrix_base const& a)
    {
        copy_elements(a);
    }

    // copies the elements of Matrix_base a to the elements of this Matrix_base
    // AND updates the ownership of those elements to this Matrix_base
    //
    // NOTE: if Matrix_base a can be transferred directly to this Matrix_base,
    // it will be...  otherwise space will for a's elements will be dynamically
    // allocated prior to the copy
    void base_copy(Matrix_base const& a)
    {
        if (a.xfer) // a is about to be deleted, so we transfer instead of copy
        {
            elems = a.elems;
            a.xfer = false;
            a.owns = false;
        }
        else // a needs to outlive the call, so we allocate and copy
        {
            elems = new T[a.sz];
            copy_elements(a);
        }

        // update ownership and transfer state
        owns = true;
        xfer = false;
    }

    // gets the elements of a local matrix out of a function without copying...
    // set's x's transfer and ownership state, and unsets this Matrix_base's
    // owership state
    void base_xfer(Matrix_base& x)
    {
        if (!owns)
            error("cannot xfer() non-owner");

        owns = false; // now elements are "safe" from deletion by original owner
        x.xfer = true; // target asserts temporary ownership
        x.owns = true;
    }

    // function template that applies the function f to each of this
    // Matrix_base's elements
    // NOTE: here, the function f() takes a single argument and returns the
    // type F
    template<typename F>
    void base_apply(F f)
    {
        // for (size_t i = 0; i < size(); i++) // loop over elements
        for (size_t i = 0; i < sz; i++) // loop over elements
            f(elems[i]); // apply f() to each
    }

    // function template that applies the function f to each of this
    // Matrix_base's elements along with c
    // NOTE: here, the function f() takes two arguments... where one is an
    // element and the other is c
    template<typename F>
    void base_apply(F f, T const& c)
    {
        // for (size_t i = 0; i < size(); i++) // loop over elements
        for (size_t i = 0; i < sz; i++) // loop over elements
            f(elems[i], c); // apply f() to each along with c
    }

    void operator=(Matrix_base const&) = delete; // prohibit ordinary copying
    Matrix_base(Matrix_base const&) = delete; // of this Matrix_base
};

}

#endif

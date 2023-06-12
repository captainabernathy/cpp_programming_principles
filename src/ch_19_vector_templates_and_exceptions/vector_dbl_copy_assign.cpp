// to prevent accidental compilation
#ifndef NO_PUSH_BACK
#include "vector_dbl.hpp"

#include <algorithm> // for copy()

// copy assignment operator
// gets called when a vector is assigned to from another vector
// it creates a new vector whose size is equal to rhs, copies the values
// of the elements in rhs to the new vector's elements, and returns a
// reference to the new vector
// NOTE: if the capacity of rhs does not exceed the capacity of this vector,
// then this vector's capacity remains unchanged
vector& vector::operator=(vector const& rhs)
{
    if (this == &rhs)
        return *this; // avoid self assignment

    if (rhs.sz <= cap) // don't need to allocate new space
    {
        // copy the elements from rhs to this vector's elements
        std::copy(rhs.elems, rhs.elems + rhs.sz, elems);
        sz = rhs.sz; // update this vector's size
        return *this; // return self-reference
    }

    double *d = new double[rhs.sz]; // allocate new space

    // copy the elements from rhs to the new space
    std::copy(rhs.elems, rhs.elems + rhs.sz, d);
    delete[] elems; // deallocate space allocated for this vector's elements

    elems = d; // set this vector's element pointer to d
    cap = sz = rhs.sz; // update this vector's capacity and size

    return *this; // return self-reference
}

#endif

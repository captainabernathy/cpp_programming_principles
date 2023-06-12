// to prevent accidental compilation
#ifndef NO_PUSH_BACK
#include "vector_dbl.hpp"

// move assignment operator
// gets called by the compiler when moving a large collection of elements
// into a vector is more efficient than copying them to it by assignment
// NOTE: && indicates an rvalue reference
// move operations NEVER take const arguments as they modify their input and
// make it 'empty'
vector& vector::operator=(vector&& rhs)
{

    if (this == &rhs)
        return *this; // avoid self assignment

    delete[] elems; // deallocate space allocated for this vector's elements
    sz = rhs.sz; // update this vector's size
    cap = rhs.cap;  // update this vector's capacity
    // set this vector's element pointer to rhs's element pointer
    elems = rhs.elems;

    // empty rhs
    rhs.elems = nullptr; // set rhs's element pointer to null
    rhs.sz = rhs.cap = 0; // set rhs's size and capacity to 0

    return *this; // return self-reference
}

#endif

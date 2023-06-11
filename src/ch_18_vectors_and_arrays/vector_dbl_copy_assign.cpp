// to prevent accidental compilation
#ifndef NO_ASSIGN
#include "vector_dbl.hpp"
#include <algorithm> // for copy()

// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
#include <iostream> // for cout
#endif

// copy assignment operator
// gets called when a vector is assigned to from another vector
// it creates a new vector whose size is equal to rhs, copies the values
// of the elements in rhs to the new vector's elements, and returns a
// reference to the new vector
vector& vector::operator=(vector const& rhs)
{
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
    std::cout << "copy assignment\n";
#endif
    double *p = new double[rhs.sz]; // allocate new space
    
    // copy elements from rhs into p
    std::copy(rhs.elems, rhs.elems + rhs.sz, p);
    delete[] elems; // deallocate space allocated for this vector's elements
    
    elems = p; // set this vector's element pointer to p
    sz = rhs.sz; // update this vector's size
    
    return *this; // return self-reference
}

#endif

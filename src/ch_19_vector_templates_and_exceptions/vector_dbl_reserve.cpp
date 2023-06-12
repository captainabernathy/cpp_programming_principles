// to prevent accidental compilation
#ifndef NO_RESERVE
#include "vector_dbl.hpp"

#include <algorithm> // for copy()

// reserves space for rsvp number of elements in a vector, and
// updates the vector's capacity to rsvp
void vector::reserve(size_t rsvp)
{
    if (rsvp <= cap)
        return ; // never decrease allocation

    double *d = new double[rsvp]; // allocate new space
    
    // copy the elements in this vector into the new space
    std::copy(elems, elems + sz, d);
    
    // deallocate the space previously allocated for this vector's elements
    delete[] elems;
    
    elems = d; // set this vector's element pointer to the new space
    cap = rsvp; // update this vector's capacity
}

#endif

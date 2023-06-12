// to prevent accidental compilation
#ifndef NO_PUSH_BACK
#include "vector_dbl.hpp"

// initializes a new element at the end of a vector to d and increases the
// vector's size by one
void vector::push_back(double d)
{
    if (cap == 0) // when empty, reserve space for 8 elements
        reserve(8);
    else if (cap == sz) // when full, reserve space for 2X the capacity
        reserve(2 * cap);

    elems[sz] = d; // insert d to end of this vector
    sz++; // increase this vector's size
}

#endif

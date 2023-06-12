// to prevent accidental compilation
#ifndef NO_RESIZE
#include "vector_dbl.hpp"

#include <algorithm> // for fill()

// resizes a vector to have new_size number of elements, initializes
// each new element to 0.0, and updates the vector's size to new_size
void vector::resize(size_t new_size)
{
    // reserve space for new_size number of elements in this vector
    reserve(new_size);

    // set elements in this vector between (elems + sz) and (elems + new_size)
    // to 0.0...
    // including (elems + sz) but not (elems + new_size)
    std::fill(elems + sz, elems + new_size, 0.0);
    
    sz = new_size; // update this vector's size
}

#endif

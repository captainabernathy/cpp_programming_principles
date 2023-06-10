#ifndef VECTOR_RESIZE_HPP
#define VECTOR_RESIZE_HPP

#include <vector_utils/vector_class.hpp>

#ifdef VECTOR_T
#include <algorithm> // for fill()
#endif

// resizes this vector to new_size and initializes new elements to val provided
// that new_size is greater than this vector's current size
// new elements are added to the end of this vector
// when new_size is less than this vector's current size the existing elements
// in this vector that exceed new_size are invalidated
#ifndef VECTOR_T
template<typename T, typename A>
void vector<T, A>::resize(size_type new_size, T val)
#else
template<typename T>
void vector<T>::resize(size_type new_size, T val)
#endif
{
    reserve(new_size); // make space for new elemens

#ifndef VECTOR_T
    // loop runs when there's space to fill at the end of this vector
    for (size_type i = sz; i < new_size; i++)
        alloc.construct(&elems[i], val); // initialize newly added elements

    // loop runs when this vector's size exceeds new_size
    for (size_type i = new_size; i < sz; i++)
        alloc.destroy(&elems[i]);  // invalidate old elements
#else
    std::fill(elems + sz, elems + new_size, val);
#endif
    sz = new_size; // update size
}

#endif

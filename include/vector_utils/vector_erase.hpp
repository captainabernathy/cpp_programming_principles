#ifndef VECTOR_ERASE_HPP
#define VECTOR_ERASE_HPP

#include <vector_utils/vector_class.hpp>

// removes the element at position p in this vector and returns a pointer to
// the element after p
template<typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::erase(iterator p)
{
    if (p == end())  // nothing to delete here
        return p;

    // copy the elements after p to the end of this array one position to the
    // left
    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos; // copy elements one position to left

    // destroy/invalidate surplus copy of last element
    alloc.destroy(&*(end() - 1));
    --sz; // update size
    return p;
}

#endif

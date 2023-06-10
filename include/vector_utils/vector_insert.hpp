#ifndef VECTOR_INSERT_HPP
#define VECTOR_INSERT_HPP

#include <vector_utils/vector_class.hpp>

// inserts val before the element at p in this vector and returns an iterator
// to the newly inserted element
template<typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::insert(iterator p, T const& val)
{
    size_type idx = p - begin();
    if (size() == capacity())
        reserve(size() == 0 ? 8 : 2 * size()); // make sure we have space

    // first, copy last element into unitialized space
    alloc.construct(elems + sz, back());
    ++sz; // update size
    
    iterator pp = begin() + idx; // the place to put the value

    // copy the elements from the last element up (down) to pp one position to
    // the right
    for (iterator pos = end() - 1; pos != pp; --pos)
        *pos = *(pos - 1); // copy elements one position to the right

    *(begin() + idx) = val; // insert val
    
    return pp; // return iterator to val
}

#endif

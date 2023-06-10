#ifndef VECTOR_PUSH_BACK_HPP
#define VECTOR_PUSH_BACK_HPP

#include <vector_utils/vector_class.hpp>

// inserts t at the end of this vector and updates this vector's size

// not defined when vector<T,A> needed
#ifndef VECTOR_T
template<typename T, typename A>
void vector<T, A>::push_back(T const& t)
#else
template<typename T>
void vector<T>::push_back(T const& t)
#endif
{
    if (cap == 0)  // reserve space for 8 elements when this vector is empty
        reserve(8);
    else if (sz == cap)   // reserve space for twice as many element when this
        reserve(2 * cap); // vector is full

// not defined when vector<T,A> needed
#ifndef VECTOR_T
    alloc.construct(&elems[sz], t); // insert t at the end of this vector
#else
    elems[sz] = t; // insert t at the end of this vector
#endif

    sz++; // update this vector's size
}

#endif

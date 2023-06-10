#ifndef VECTOR_RESERVE_HPP
#define VECTOR_RESERVE_HPP

#include <vector_utils/vector_class.hpp>

// not defined when vector<T,A> needed
#ifdef VECTOR_T
#include <algorithm> // for copy()
#endif

// reserves space for rsvp elements in this vector provided that rsvp is
// greater than this vector's current capacity... does nothing when rsvp is
// less than or equal to this vector's current capacity

// not defined when vector<T,A> needed
#ifndef VECTOR_T
template<typename T, typename A>
void vector<T, A>::reserve(size_type rsvp)
#else
template<typename T>
void vector<T>::reserve(size_type rsvp)
#endif
{
    if (rsvp <= cap)
        return ; // don't decrease allocation

// not defined when vector<T,A> needed
#ifndef VECTOR_T
    T *t = alloc.allocate(rsvp); // allocate new space
    
    // uses existing elements to construct elements in new space
    for (size_type i = 0; i < sz; i++)
        alloc.construct(&t[i], elems[i]);

    // destroy elements in old space
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);

    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);
#else
    T* t = new T[rsvp]; // allocate new space

    // copy the elements in this vector into the new space
    std::copy(elems, elems + sz, t);

    // deallocate the space previously allocated for this vector's elements
    delete[] elems;
#endif

    elems = t; // update elements
    cap = rsvp; // update capacity
}

#endif

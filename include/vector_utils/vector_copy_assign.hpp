#ifndef VECTOR_COPY_ASSIGN_HPP
#define VECTOR_COPY_ASSIGN_HPP

#include <vector_utils/vector_class.hpp>

#ifdef VECTOR_T
#include <algorithm> // for copy()
#endif

// overwrites this vector's elements with a copy of the elements contained
// in the vector rhs and updates this vector's size and capacity to the
// size of the elements in rhs provided that the capacity of rhs exceeds
// this vector's capacity...
// in the case that the capacity of this vector exceeds the capacity of rhs,
// only the size of this vector is updated while its capacity remains
// unchanged
#ifndef VECTOR_T
template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector const& rhs)
#else
template<typename T>
vector<T>& vector<T>::operator=(vector const& rhs)
#endif
{
    if (this == &rhs) // short circuit when rhs already refers to this vector
        return *this;

    // when there's no need to allocate more space in this vector
    if (rhs.cap <= cap)
    {
#ifndef VECTOR_T
        // copy up to rhs.sz elements from rhs into this vector at the same
        // corresponding position
        for (size_type i = 0; i < rhs.sz; i++)
            alloc.construct(&elems[i], rhs.elems[i]);

        // invalidate any elements in this vector that exceed the size of rhs
        for (size_type i = rhs.sz; i < sz; i++)
            alloc.destroy(&elems[i]);

        sz = rhs.sz; // update size
        return *this;
#else
        // copy the elements from rhs to this vector's elements
        std::copy(rhs.elems, rhs.elems + rhs.sz, elems);
        sz = rhs.sz; // update this vector's size
        return *this; // return self-reference
#endif
    }

#ifndef VECTOR_T
    // allocate space for rhs.sz elements
    T *t = alloc.allocate(rhs.sz);

    // fill newely allocated space with the elements in rhs
    for (size_type i = 0; i < rhs.sz; i++)
        alloc.construct(&t[i], rhs.elems[i]);

    // invalidate this vector's elements
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);
    
    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);
#else
    T* t = new T[rhs.sz]; // allocate new space

    // copy the elements from rhs to the new space
    std::copy(rhs.elems, rhs.elems + rhs.sz, t);
    delete[] elems; // deallocate space allocated for this vector's elements
#endif

    cap = sz = rhs.sz; // update size and capacity
    elems = t; // update this vectors elements
    return *this;
}

#endif

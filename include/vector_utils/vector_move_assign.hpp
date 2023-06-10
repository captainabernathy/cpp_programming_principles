#ifndef VECTOR_MOVE_ASSIGN_HPP
#define VECTOR_MOVE_ASSIGN_HPP

#include <vector_utils/vector_class.hpp>

// move assignment operator
// directly assigns this vector's elements to the elements of rhs and updates
// this vector's size and capacity to the size of and capacity of rhs
// subsequently, the size and capacity of rhs will be 0, and its elements
// will be NULL
#ifndef VECTOR_T
template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& rhs)
#else
template<typename T>
vector<T>& vector<T>::operator=(vector&& rhs)
#endif
{
    if (this == &rhs)  // short circuit when rhs already refers to this vector
        return *this;

#ifndef VECTOR_T
    // invalidate all of this vector's elements
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);

    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);
#else
    delete[] elems; // deallocate space allocated for this vector's elements
#endif

    sz = rhs.sz; // update size
    cap = rhs.cap; // update capacity
    elems = rhs.elems; // update this vector's elements

    rhs.elems = nullptr; // set rhs's elements to NULL
    rhs.sz = rhs.cap = 0; // set rhs's size and capacity to 0

    return *this;
}

#endif

// to prevent accidental compilation
#ifndef NO_MOVE
#include "vector_dbl.hpp"

// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
#include <iostream> // for cout
#endif

// move assignment operator
// gets called by the compiler when moving a large collection of elements
// into a vector is more efficient than copying them to it by assignment
// NOTE: && indicates an rvalue reference
// move operations NEVER take const arguments as they modify their input and
// make it 'empty'
vector& vector::operator=(vector&& a)
{
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
    std::cout << "move assignment\n";
#endif
    delete[] elems; // deallocate space allocated for this vector's elements

    elems = a.elems; // copy a's elements to this vector's element
    sz = a.sz; // update size
    
    // 'empty vector a'
    a.elems = nullptr;
    a.sz = 0;
    
    return *this; // return reference
}

#endif

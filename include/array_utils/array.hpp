#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // for size_t

template<typename T, size_t N>
struct array {
    // typedef size_t size_type;
    using size_type = size_t;

    // typedef T value_type;
    using value_type = T;

    // typedef T* iterator;
    using iterator = T*;

    // typedef const T* const_iterator;
    using const_iterator = T const*;

    value_type elems[N]; // no explicit construct/copy/destroy needed

    // returns an iterator to the first element in this vector
    iterator begin()
    {
        return elems;
    }

    // returns a const interator to the first element in this vector
    const_iterator begin() const
    {
        return elems;
    }

    // returns an iterator to one past the last element in this vector
    iterator end()
    {
        return elems + N;
    }

    // returns a const iterator to one past the last element in this vector
    size_type size() const
    {
        return N;
    }

    // member access operator invoked by non-const objects
    // returns reference to the element of this array at index n
    T& operator[](size_type n)
    {
        return elems[n];
    }

    // member access operator invoked by const objects
    // returns a constant reference to the element of this array at index n
    T const& operator[](size_type n) const
    {
        return elems[n];
    }

    // provides range-checked access to this array
    // invoked by const objects
    // returns a constant reference to the element of this array at index n
    T const& at(size_type n) const;  // NOT IMPLEMENTED
   
    // provides range-checked access to this array
    // invoked by non-const objects
    // returns a reference to the element of this array at index n
    T& at(size_type n); // NOT IMPLEMENTED

    // returns a pointer to the first element of this array
    // invoked by non-const objects
    T* data()
    {
        return elems;
    }

    // returns const pointer to the first element of this array
    // invoked by const objects
    T const* data() const
    {
        return elems;
    }
};

#endif

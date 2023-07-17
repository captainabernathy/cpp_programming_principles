#ifndef VECTOR_CHECKED_HPP
#define VECTOR_CHECKED_HPP

#include <vector> // for vector
#include <stdexcept> // for out_of_range
#include <io_utils/to_string.hpp> // for to_string<>()

// template that extends the standard library template for a vector of
// type T to include range checking
template<typename T>
struct Vector : std::vector<T> {
    using size_type = typename std::vector<T>::size_type;
    using std::vector<T>::vector;

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index i
    // throws an out_of_range() exception if i is an invalid index
    T& operator[](size_type i)
    {
        if (i < 0 || this->size() <= i)
            // throw Range_error{(size_t)i};
            throw std::out_of_range("Range error at index " + to_string(i));
        return std::vector<T>::operator[](i);
    }

    // member access operator invoked by const vectors
    // returns a constant reference to the element of this vector at index i
    // throws an out_of_range() exception if i is an invalid index
    T const& operator[](size_type i) const
    {
        if (i < 0 || this->size() <= i)
            // throw Range_error{(size_t)i};
            throw std::out_of_range("Range error at index " + to_string(i));
        return std::vector<T>::operator[](i);
    }
};

// hack to get range-checked vector
#define vector Vector

#endif

#ifndef ARRAY_FILL_HPP
#define ARRAY_FILL_HPP

#include <array_utils/array.hpp> // for array<>
#include <cstddef> // for size_t

// template for a function that fills an N element array of type T (array<T,N>)
// with the value of type T provied to val
template<typename T, size_t N>
void fill(array<T, N>& arr, T const& val)
{
    for (size_t i = 0; i < N; i++)
        arr[i] = val;
}

#endif

#ifndef ARRAY_UTILS_HPP
#define ARRAY_UTILS_HPP

// provides:
// <typename T, size_t N>
// array (template class)
//      T elems[N]
//      T const* begin() const
//      T* begin()
//      T* end()
//      size_t size() const
//      T& operator[](size_t n)
//      T const& operator[](size_t n) const
//////////////////////////////////////////////////////////
//      T const& at(size_t n) const // NOT IMPLEMENTED  //
//      T& at(size_t n)             // NOT IMPLEMENTED  //
//////////////////////////////////////////////////////////
//      T* data()
//      T const* data() const
#include <array_utils/array.hpp>

// provides:
// <typename T, size_t N>
// void fill(array<T,N>& arr, T const& val)
#include <array_utils/array_fill.hpp>

#endif

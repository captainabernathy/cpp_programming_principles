#ifndef MAKE_REF_HPP
#define MAKE_REF_HPP

#include <array_ref_utils/array_ref.hpp> // for Array_ref<>
#include <vector> // for vector
#include <iostream> // for cout

// function template that returns an Array_ref of type T initialized with the
// element pointer p and a size of s
//
// NOTE: if p is NULL, then the returned Array_ref will be initialized with
// a nullptr and a size of 0
template<typename T>
Array_ref<T> make_ref(T *p, size_t s)
{
    std::cout << "make_ref(T *p, size_t s)\n";
    return (p) ? Array_ref<T>(p, s) : Array_ref<T>(nullptr, 0);
}

// function template that returns an Array_ref of type T with an element
// pointer initialized to the address of the first element in v and a size
// equal to v's size
//
// NOTE: if v is empty, then the returned Array_ref will be initialized with
// a nullptr and a size of 0
template<typename T>
Array_ref<T> make_ref(std::vector<T>& v)
{
    std::cout << "make_ref(std::vector<T>& v)\n";
    return (v.size()) ? Array_ref<T>(&v[0], v.size()) : Array_ref<T>(nullptr,
                                                                     0);
}

// function template that returns an Array_ref of type T that is initialized
// from the array p, which contains n element
//
// NOTE: if p is NULL, then the returned Array_ref will be initialized with
// a nullptr and a size of 0
template<typename T, size_t N>
Array_ref<T> make_ref(T (&p)[N])
{
    std::cout << "make_ref(T (&p)[N])\n";
    return Array_ref<T>(p, N);
}

#endif

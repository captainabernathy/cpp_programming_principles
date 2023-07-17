#ifndef ARRAY_REF_UTILS_HPP
#define ARRAY_REF_UTILS_HPP

// provides:
// template<typename T>
// class Array_ref
#include <array_ref_utils/array_ref_utils.hpp>

// provides:
// template<typename T>
// Array_ref<T> make_ref(T *p, size_t s)
//
// template<typename T>
// Array_ref<T> make_ref(vector<T>& v)
//
// template<typename T, size_t N>
// Array_ref<T> make_ref(T (&p)[N])
#include <array_ref_utils/make_ref.hpp>

#endif

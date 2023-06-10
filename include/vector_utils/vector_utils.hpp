#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

// provides:
// template<typename T, typename A = std::allocator<T>>
// vector (template class)
//      vector(size_t n)
//      vector(initializer_list<T> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector const& rhs)
//      vector& operator=(vector&& rhs)
//      T& operator[](size_t idx)
//      T const& operator[](size_t idx) const
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)
//      void resize(size_t new_size, T val = T())
//      void push_back(T const& t)
//      iterator begin()
//      const_iterator begin() const
//      iterator end()
//      const_iterator const* end() const
//      T& back()
//      iterator insert(T* p, T const& val)
//      iterator erase(T* p)
// OR
// template<typename T>
// vector (template class)
//      vector(size_t n)
//      vector(initializer_list<T> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector const& rhs)
//      vector& operator=(vector&& rhs)
//      T& operator[](size_t idx)
//      T const& operator[](size_t idx) const
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)
//      void resize(size_t new_size, T val = T())
//      void push_back(T const& t)
#include <vector_utils/vector_class.hpp>

// provides:
// template<typename T, typename A>
// vector<T, A>& vector<T, A>::operator=(vector const& rhs)
// OR
// template<typename T>
// vector<T>& vector<T>::operator=(vector const& rhs)
#include <vector_utils/vector_copy_assign.hpp>

// provides:
// template<typename T, typename A>
// vector<T, A>& vector<T, A>::operator=(vector&& rhs)
// OR
// template<typename T>
// vector<T>& vector<T>::operator=(vector&& rhs)
#include <vector_utils/vector_move_assign.hpp>

// provides:
// template<typename T, typename A>
// void vector<T, A>::reserve(size_type rsvp)
// OR
// template<typename T>
// void vector<T>::reserve(size_type rsvp)
#include <vector_utils/vector_reserve.hpp>

// provides:
// template<typename T, typename A>
// void vector<T, A>::resize(size_type new_size, T val)
// OR
// template<typename T>
// void vector<T>::resize(size_type new_size, T val)
#include <vector_utils/vector_resize.hpp>

// provides:
// template<typename T, typename A>
// void vector<T, A>::push_back(T const& t)
// OR
// template<typename T>
// void vector<T>::push_back(T const& t)
#include <vector_utils/vector_push_back.hpp>

// not defined when vector<T,A> needed
#ifndef VECTOR_T
// provides:
// template<typename T, typename A>
// typename vector<T,A>::iterator vector<T,A>::insert(iterator p, T const& val)
#include <vector_utils/vector_insert.hpp>

// provides:
// template<typename T, typename A>
// typename vector<T,A>::iterator vector<T, A>::erase(iterator p)
#include <vector_utils/vector_erase.hpp>
#endif

#endif

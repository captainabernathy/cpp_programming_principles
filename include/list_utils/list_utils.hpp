#ifndef LIST_HPP
#define LIST_HPP

// provides:
// template<typename T>
// list (template class)
//      iterator (class)
//      list()
//      iterator begin()
//      iterator end()
//      void push_front(T const& t)
//////////////////////////////////////////////////////////////////////
//      iterator insert(iterator p, T const& v) // NOT IMPLEMENTED  //
//      iterator erase(iterator p)              // NOT IMPLEMENTED  //
//      void push_back(T const& t)              // NOT IMPLEMENTED  //
//      void pop_front()                        // NOT IMPLEMENTED  //
//      void pop_back()                         // NOT IMPLEMENTED  //
//      T& front()                              // NOT IMPLEMENTED  //
//      T& back()                               // NOT IMPLEMENTED  //
//////////////////////////////////////////////////////////////////////
//
// and
// template<typename T>
// link (template class)
//      T value
//      link *prev
//      link *next
//      link(T const& t = T(), link *p = nullptr, link *n = nullptr)
// OR
// link (class)
//      string value
//      link *prev
//      link *next
//      link(string const& s, link *p = nullptr, link *n = nullptr)
#include <list_utils/list_class.hpp>

// provides:
// template<typename T>
// class list<T>::iterator (template class)
//      iterator(link<T> *p)
//      iterator& operator++()
//      iterator& operator--()
//      T& operator*()
//      bool operator==(iterator const& lhs, iterator const& rhs)
//      bool operator!=(iterator const& lhs, iterator const& rhs)
#include <list_utils/list_iterator.hpp>

// provides:
// template<typename T>
// typename list<T>::iterator list<T>::begin()
#include <list_utils/list_begin.hpp>

// provides:
// template<typename T>
// typename list<T>::iterator list<T>::end()
#include <list_utils/list_end.hpp>

// provides:
// template<typename T>
// void list<T>::push_front(T const& t)
#include <list_utils/list_push_front.hpp>

#endif

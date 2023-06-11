#ifndef LINK_STR_UTILS_HPP
#define LINK_STR_UTILS_HPP

// provides:
/// link (class)
//      string value
//      link *prev
//      link *next
//      link(string const& s, link *p = nullptr, link *n = nullptr)
//
// link* insert(link *p, link *n)
// link* add(link *p, link *n)
// link* erase(link *p)
// link* find(link *p, string const& s)
// link* advance(link *p, int n)
//
// OR
// link (class)
//      string value
//      link(string const& v, link *p = nullptr, link *n = nullptr)
//      link* insert(link *n)
//      link* erase()
//      link* find(string const& s)
//      link* get_next() const
//      link* get_prev() const
#include "link_str.hpp"

// displays the contents of a list starting from link p
void print_all(link *p);

#endif

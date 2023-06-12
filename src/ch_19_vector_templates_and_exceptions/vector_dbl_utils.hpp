#ifndef VECTOR_DBL_UTILS_HPP
#define VECTOR_DBL_UTILS_HPP

// vector (class)
//      vector()
//      explicit vector(size_t n)
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector const& rhs)
//      vector& operator=(vector&& rhs)
//      double& operator[](size_t i)
//      double operator[](size_t i) const
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)
//      void resize(size_t new_size)
//      void push_back(double d)
#include "vector_dbl.hpp" // for vector
#include <string> // for string

// function that outputs the contents of vector v prepended by string s
void print_vec(vector const& v, std::string const& s);

#endif

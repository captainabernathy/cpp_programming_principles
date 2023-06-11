#ifndef VECTOR_DBL_UTILS_HPP
#define VECTOR_DBL_UTILS_HPP

// provides:
// vector (class)
//      vector()
//      explicit vector(size_t s)
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      vector(vector&& a)
//      ~vector()
//      size_t size() const
//      vector& operator=(vector const& v)
//      vector& operator=(vector&& a)
//////////////////////////////////////////
//      OPTIONALLY                      //
//      double get(size_t n) const      //
//      void set(size_t n, double v)    //
//////////////////////////////////////////
//////////////////////////////////////////////////////
//      double& operator[](size_t n)                //
//      OR                                          //
//      double *operator[](size_t n) // problematic //
//      OR                                          //
//      double operator[](size_t n) // problematic  //
//////////////////////////////////////////////////////
//      double operator[](size_t n) const
#include "vector_dbl.hpp" // for vector
#include <string> // for string

// outputs the contents of the vector it receives and prepends each
// with the string it receives
void print_vector(vector const&, std::string const&);

#endif

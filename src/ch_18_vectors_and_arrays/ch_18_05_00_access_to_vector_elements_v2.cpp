// program tests the implementation of a vector class that stores elements of
// type double, which now supports a member access operator that provides read
// and write access to an element, but it does so by returning a pointer to the
// element, which means that access operations require dereferencing the
// pointer
//
// vector (class)
//      explicit vector(size_t s)
//      size_t size() const
//      double *operator[](size_t n)
//      ~vector()

#include <iostream> // for cout

// make double *vector::operator[](size_t n) visible to syntax checkers
#ifndef READ_WRITE_PTR
#define READ_WRITE_PTR
#endif

#include "vector_dbl.hpp" // for vector

int main()
{
    // build a vector of 10 elements
    vector v1(10);

    // works but is ugly and error-prone
    for (size_t i = 0; i < v1.size(); i++)
    {
        *v1[i] = ((1.1 * i) + 1.1); // assign value to vector element
        std::cout << *v1[i] << '\n'; // write result to stdout
    }

    return 0;
}

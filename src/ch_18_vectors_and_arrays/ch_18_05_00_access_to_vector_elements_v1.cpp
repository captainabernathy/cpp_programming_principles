// program tests the implementation of a vector class that stores elements of
// type double, which now supports a member access operator that only provides
// read access to an element, but does NOT support assignment to an element
//
// vector (class)
//      vector(initializer_list<double> lst)
//      double operator[](size_t n)
//      ~vector()

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    // build a vector from an initializer list
    vector v {1, 2, 3};

    // read element from vector into x
    int x = v[2];

    // write result to stdout
    std::cout << x << '\n';
    
    // write from variable to vector element
    // v[2] = x; // ERROR... v[2] is not an lvalue

    return 0;
}

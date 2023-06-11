// program tests the implementation of a vector class that stores elements of
// type double, which now supports a copy constructor
//
// vector (class)
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      ~vector()
//
// void print_vector(vector const&, string const&)

#include <iostream> // for cout

// make vector::get() and vector::set() methods visible to syntax checkers
#ifndef GET_AND_SET
#define GET_AND_SET
#endif

#include "vector_dbl_utils.hpp" // for vector, print_vector()

int main()
{
    using std::cout;

    // build a vector from an initializer list
    vector v1 {1.1, 2.2, 3.3};

    // build a vector via copy construction
    vector v2(v1);

    // output contents of each vector
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");

    return 0;
}

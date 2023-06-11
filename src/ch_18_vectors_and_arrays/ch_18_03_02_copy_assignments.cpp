// program tests the implementation of a vector class that stores elements of
// type double, which now supports a copy assignment operator
//
// vector (class)
//      vector()
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      ~vector()
//      vector& operator=(vector const& v)
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

    vector v3;
    // build up vector via copy assignment
    v3 = v2;

    // output contents of each vector
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");
    cout << '\n';

    print_vector(v3, "v3");

    return 0;
}

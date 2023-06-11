// program tests the implementation of a vector class that stores elements of
// type double, which now supports an initializer list constructor
//
// vector (class)
//      explicit vector(size_t s)
//      vector(initializer_list<double> lst)
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

    // build a vector using an initializer list
    vector v1 {1, 2, 3};

    // build a vector using the explict constructor
    vector v2(3); // three elements initialized to 0.0

    //NOTE: the '=' before initializer list is optional
    vector v3 = {3, 4, 5};

    // output contents of each vector
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");
    cout << '\n';

    print_vector(v3, "v3");

    return 0;
}

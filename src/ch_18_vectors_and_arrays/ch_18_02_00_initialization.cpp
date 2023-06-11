// program tests the implementation of a vector class that stores elements of
// type double
//
// vector (class)
//      explicit vector(size_t s)
//      ~vector()
//      double get(size_t n) const
//      void set(size_t n, double v)

#include <iostream> // for cout

// make vector::get() and vector::set() methods visible to syntax checkers
#ifndef GET_AND_SET
#define GET_AND_SET
#endif

#include "vector_dbl.hpp" // for vector

// a tester function for the the user-defined vector type...
void f();

int main()
{
    using std::cout;

    // build a few vectors
    vector v(3);
    vector v2(3);

    // write to each of the vectors
    v.set(1, 99);
    v2.set(0, 88);

    // read from each of the vectors
    cout << "v.get(1): " << v.get(1) << " v2.get(0): " << v2.get(0) << '\n';

    // f(2);  // causes double free

    return 0;
}

// NOTE: function call results in a double free...
// since it creates 2 vector objects that go out of scope, vector's destructor
// is called twice...
// and since vector does not contain a copy assignment operator, the assignment
// of one vector to another in this function creates an alias between the two...
// SO the destruction of one's elements results in the destruction of the
// other's, which results in an attempt by the second object's destructor to
// free already freed memory
void f()
{
    vector v(3); // vector of 3 elements
    v.set(2, 2.2); // set last element of v to 2.2
    vector v2 = v;  // shallow assignment.. since vector has no copy constructor
    std::cout << "in f(int n)...\n";
    std::cout << "v2.get(2): " << v2.get(2) << " v.get(2): " << v.get(2)
        << '\n';
    // double free when function goes out of scope
}

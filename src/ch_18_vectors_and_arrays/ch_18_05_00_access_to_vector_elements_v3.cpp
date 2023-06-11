// program tests the implementation of a vector class that stores elements of
// type double, which now supports a member access operator that provides read
// and write access to an element
//
// it does so by returning a reference to an element... which means that
// certain access operations will fail for constant vectors since reading from
// a constant is ok, but writing to a constat is illegal
//
// vector (class)
//      explicit vector(size_t s)
//      size_t size() const
//      double& operator[](size_t n)
//      ~vector()

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    // build a vector of 10 elements
    vector v(10);

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = ((1.1 * i) + 1.1); // assign value to vector element
        std::cout << v[i] << '\n'; // write result to stdout
    }

    return 0;
}

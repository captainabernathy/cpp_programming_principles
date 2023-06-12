// program tests the implementation of a vector class that stores elements of
// type double, which now supports a size() and a capacity() method
//
// vector (class)
//      vector()
//      ~vector()
//      size_t size() const
//      size_t capacity() const

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    using std::cout;

    vector v;
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << '\n'; // 0

    return 0;
}

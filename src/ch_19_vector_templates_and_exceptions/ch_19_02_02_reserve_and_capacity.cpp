// program tests the implementation of a vector class that stores elements of
// type double, which now supports a reserve() method
//
// vector (class)
//      vector()
//      ~vector()
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    using std::cout;

    vector v;
    cout << "v.size(): " << v.size() << " (before reserve())\n"; // 0
    cout << "v.cap(): " << v.capacity() << " (before reserve())\n\n"; // 0

    v.reserve(10);
    cout << "v.size(): " << v.size() << " (after v.reserve(10))\n"; // 0

    cout << "v.cap(): " << v.capacity() << " (after v.reserve(10))\n\n"; // 10

    v.reserve(5);
    cout << "v.size(): " << v.size() << " (after v.reserve(5))\n"; // 0

    // NOTE: capacity does not shrink
    cout << "v.cap(): " << v.capacity() << " (after v.reserve(5))\n"; // 10

    return 0;
}

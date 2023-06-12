// program tests the implementation of a vector class that stores elements of
// type double, which now supports a reserve() method
//
// vector (class)
//      vector()
//      ~vector()
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)
//      void resize(size_t new_size)

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    using std::cout;

    vector v; // build a vector

    cout << " before reserve()\n";
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << "\n\n"; // 0

    v.reserve(10); // reserve space for 10 elements in vector v
    cout << "after v.reserve(10)\n";
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << "\n\n"; // 10

    v.resize(4); // resizie vector v to 4
    cout << "after v.resize(4)\n";
    cout << "v.size(): " << v.size() << '\n'; // 4
    cout << "v.capacity(): " << v.capacity() << '\n'; // 10

    return 0;
}

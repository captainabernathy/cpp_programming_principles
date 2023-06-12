// program tests the implementation of a vector class that stores elements of
// type double, which now supports a push_back() method
//
// vector (class)
//      vector()
//      ~vector()
//      double& operator[](size_t i)
//      double operator[](size_t i) const
//      size_t size() const
//      size_t capacity() const
//      void reserve(size_t rsvp)
//      void resize(size_t new_size)
//      void push_back(double d)

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

int main()
{
    using std::cout;

    vector v; // build a vector
    cout << "before reserve()...\n";
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << "\n\n"; // 0

    v.push_back(7); // add an element to v
    cout << "after v.push_back(7)...\n";
    cout << "v.size(): " << v.size() << '\n'; // 1
    cout << "v.capacity(): " << v.capacity() << '\n'; // 8
    cout << "v[0]: " << v[0] << "\n\n"; // 7

    v.reserve(10); // reserve space for 10 elements in v
    cout << "after v.reserve(10)...\n";
    cout << "v.size(): " << v.size() << '\n'; // 1
    cout << "v.capacity(): " << v.capacity() << "\n\n"; // 10

    v.resize(4); // resize v
    cout << "after v.resize(4)...\n";
    cout << "v.size(): " << v.size() << '\n'; // 4
    cout << "v.capacity(): " << v.capacity() << '\n'; // 10

    return 0;
}

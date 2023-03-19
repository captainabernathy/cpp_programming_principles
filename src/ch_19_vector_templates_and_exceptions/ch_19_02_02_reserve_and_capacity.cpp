// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement a reserve() method

#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
using namespace std;

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // address of first element in a vector

    // total amout of space allocated for elements in a vector
    size_t cap; // number of elements + free space... sz + free space

public:
    // public member functions
    // default constructor, sets a vector's size and capacity to 0 and the
    // pointer to its elements to null
    vector()
        : sz{0}, elem{nullptr}, cap{0} {  }

    // deallocates a vector's dynamically allocated resources
    ~vector() { delete[] elem; }

    // returns the number of elements in a vector
    size_t size() const { return sz; }

    // returns the total number of spaces allocated for elements in a vector
    size_t capacity() const { return cap; }

    // reserves space for to_reserve number of elements in a vector, and
    // updates the vector's capacity to to_reserve
    // NOTE: when to_reserve does not exceed the currently allocated amount of
    // space for a vector's elements, the vector remains unchanged
    void reserve(size_t to_reserve);
};

// reserves space for to_reserve number of elements in a vector, and
// updates the vector's capacity to to_reserve
void vector::reserve(size_t to_reserve)
{
    if (to_reserve <= cap)
        return ; // never decrease allocation

    double *d = new double[to_reserve]; // allocate new space
    
    // copy the elements in this vector into the new space
    std::copy(elem, elem + sz, d);
    
    // deallocate the space previously allocated for this vector's elements
    delete[] elem;
    
    elem = d; // set this vector's element pointer to the new space
    cap = to_reserve; // update this vector's capacity
}


int main()
{
    vector v;
    cout << "v.size(): " << v.size() << " (before reserve())" << endl; // 0
    cout << "v.cap(): " << v.capacity() << " (before reserve())" << endl; // 0
    cout << endl;

    v.reserve(10);
    cout << "v.size(): " << v.size() << " (after v.reserve(10))" << endl; // 0

    // 10
    cout << "v.cap(): " << v.capacity() << " (after v.reserve(10))" << endl;
    cout << endl;

    v.reserve(5);
    cout << "v.size(): " << v.size() << " (after v.reserve(5))" << endl; // 0

    // 10... capacity does not shrink
    cout << "v.cap(): " << v.capacity() << " (after v.reserve(5))" << endl;
    return 0;
}

// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement a resize() method

#include <iostream> // I/O library header
#include <algorithm> // algorithm library header

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // address of first element in a vector

    // total amout of space allocated for elements in a vector
    // number of elements + free space... sz + free space
    size_t cap;

public:
    // public member functions
    // default constructor, sets a vector's size and capacity to 0 and the
    // pointer to its elements to null
    vector()
        : sz {0}, elem {nullptr}, cap {0} {  }

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

    // resizes a vector to have new_size number of elements, initializes
    // each new element to 0.0, and updates the vector's size to new_size
    void resize(size_t new_size);
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

void vector::resize(size_t new_size)
{
    // reserve space for new_size number of elements in this vector
    reserve(new_size);

    // set elements in this vector between (elem + sz) and (elem + new_size)
    // to 0.0...
    // including (elem + sz) but not (elem + new_size)
    std::fill(elem + sz, elem + new_size, 0.0);
    
    sz = new_size; // update this vector's size
}

int main()
{
    using std::cout;

    vector v; // build a vector

    cout << " before reserve()" << '\n';
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << '\n'; // 0
    cout << '\n';

    v.reserve(10); // reserve space for 10 elements in vector v
    cout << "after v.reserve(10)" << '\n';
    cout << "v.size(): " << v.size() << '\n'; // 0
    cout << "v.capacity(): " << v.capacity() << '\n'; // 10
    cout << '\n';

    v.resize(4); // resizie vector v to 4
    cout << "after v.resize(4)" << '\n';
    cout << "v.size(): " << v.size() << '\n'; // 4
    cout << "v.capacity(): " << v.capacity() << '\n'; // 10

    return 0;
}

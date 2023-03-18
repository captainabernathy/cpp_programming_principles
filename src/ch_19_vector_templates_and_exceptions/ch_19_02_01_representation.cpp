#include <iostream> // I/O library header
using namespace std;

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
};

int main()
{
    vector v;
    cout << "v.size(): " << v.size() << endl; // 0
    cout << "v.capacity(): " << v.capacity() << endl; // 0

    return 0;
}

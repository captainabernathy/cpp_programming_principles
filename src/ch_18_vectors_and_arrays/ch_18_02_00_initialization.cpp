// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement an explicit constructor

#include <iostream> // for cout

// ad-hoc class meant to represent a starting point for building up a
// user-defined vector type
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

public:
    // public member functions
    // explicit constructor
    // allocates memory for a vector of s doubles
    explicit vector(size_t s)
        : sz {s}, elem {new double[s]} {  }

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of this vector
    size_t size() const { return sz; }

    // provides read access to this vector by returning the value
    // of the element at index n
    // NOTE: function does not provide any range checking
    double get(size_t n) const { return elem[n]; }

    // provides write access to this vector by assigning double v to the
    // element at index n
    // NOTE: function does not provide any range checking
    void set(size_t n, double v) { elem[n] = v; }
};

// a tester function for the the user-defined vector type...
// n has no significance at this point
void f(size_t n);

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
void f(size_t n)
{
    vector v(3); // vector of 3 elements
    v.set(2, 2.2); // set last element of v to 2.2
    vector v2 = v;  // shallow assignment.. since vector has no copy constructor
    std::cout << "in f(int n)..." << '\n';
    std::cout << "v2.get(2): " << v2.get(2) << " v.get(2): " << v.get(2)
        << '\n';
    // double free when function goes out of scope
}

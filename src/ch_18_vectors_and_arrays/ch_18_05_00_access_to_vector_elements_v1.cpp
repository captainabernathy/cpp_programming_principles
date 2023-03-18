#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template

using std::cout;
using std::endl;

class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

public:
    // public member functions
    // explicit, one-argument constructor
    // allocates memory for a vector of s doubles
    // NOTE: explicit constructors define a conversion from its argument type to
    // its class
    explicit vector(size_t s)
        : sz{s}, elem{new double[sz]}
    {
        std::fill(elem, elem + sz, 0.);
    }

    // constructor that takes an initializer list
    // it creates a vector with a size equal to the number of elements in the
    // initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz{lst.size()}, elem{new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    // gets called when a vector is initialized from another vector
    // it sets this vector's size to the input vector's size and copies the
    // the values of the input vector's elements to this vector's elements
    vector(const vector& v)
        : sz{v.sz}, elem{new double[sz]}
    {
        std::copy(v.elem, v.elem + sz, elem);
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    vector& operator=(const vector& rhs);

    // member access operator
    // provides read access to a vector by returning the value of the element
    // at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: this function only supports reading from a vector...
    // it DOES NOTE support assignment, so expressions of the form...
    // v[i] = val;
    // fail bc v[i] is not an lvalue
    double operator[](int n) { return elem[n]; }

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of a vector
    size_t size() const { return sz; }
};

// copy assignment
vector& vector::operator=(const vector& rhs)
{
    double *p = new double[rhs.sz]; // allocate new space
    
    // copy elements from rhs into p
    std::copy(rhs.elem, rhs.elem + rhs.sz, p);
    delete[] elem; // deallocate space allocated for this vector's elements
    
    elem = p; // set this vector's element pointer to p
    sz = rhs.sz; // update this vector's size
    
    return *this; // return self-reference
}

int main()
{
    // build a vector from an initializer list
    vector v {1, 2, 3};

    // read element from vector into x
    int x = v[2];

    // write result to stdout
    cout << x << endl;
    
    // write from variable to vector element
    // v[3] = x; // ERROR... v[3] is not an l value

    return 0;
}
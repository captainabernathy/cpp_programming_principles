// program implements an ad-hoc class for a vector of doubles that implements
// a member access operator that provides read and write access to an element.
// it also provides an overloaded implementation of the member access operator
// that facilitates read access to an element of a constant vector.

#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <string> // string library header
#include <initializer_list> // provides initializer_list class template

using std::cout;
using std::endl;
using std::string;

// ad-hoc class for a vector of doubles
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
        std::fill(elem, elem + sz, 0.0);
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
    vector(vector const& v)
        : sz{v.sz}, elem{new double[sz]}
    {
        std::copy(v.elem, v.elem + sz, elem);
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    vector& operator=(vector const& v);

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: returning a reference facilitates conventional indexing
    // operations for vectors
    // HOWEVER: certain indexing operations will fail for constant vectors since
    // reading from a constant is supported but writing to a constant is illegal
    double& operator[](int idx) { return elem[idx]; }

    // member access operator for constant vectors
    // provides read access to a vector by returning the value of the
    // element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: this function is allowed because it returns a value, as
    // opposed to a reference
    double operator[](int idx) const { return elem[idx]; }

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of this vector
    size_t size() const { return sz; }
};

// copy assignment
vector& vector::operator=(vector const& rhs)
{
    double *p = new double[rhs.sz]; // allocate new space
    
    // copy elements from rhs into p
    std::copy(rhs.elem, rhs.elem + rhs.sz, p);
    delete[] elem; // deallocate space allocated for this vector's elements
    
    elem = p; // set this vector's element pointer to p
    sz = rhs.sz; // update this vector's size
    
    return *this; // return self-reference
}

// tester function for const and non-const overloaded member access operators
void f(vector const& cv, vector& v);

// outputs the contents of the vector it receives and prepends each
// with the string it receives
void print_vector(vector const& v, string const& s);

int main()
{
    // initialize vectors
    vector v1 {1.1, 2.2, 3.3};
    vector v2 {4.4, 5.5, 6.6};

    // output vectors
    print_vector(v1, "v1");
    cout << endl;
    print_vector(v2, "v2");
    cout << endl;

    // test overloaded member access operator
    f(v1, v2);

    // output results
    print_vector(v1, "v1");
    cout << endl;
    print_vector(v2, "v2");

    return 0;
}

void f(vector const& cv, vector& v)
{
    double d = cv[1]; // ok to read from cv
    v[1] = v[2];  // ok to write to v
    v[2] = d;
}

void print_vector(vector const& v, string const& s)
{
    // loop over each vector and output each element prepended by s
    for (size_t i = 0; i < v.size(); i++)
        cout << s << ": " << v[i] << endl;
}

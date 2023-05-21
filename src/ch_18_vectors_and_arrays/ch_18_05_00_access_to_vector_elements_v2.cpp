// program implements an ad-hoc class for a vector of doubles that implements
// a member access operator that provides read and write access to an element,
// but it does so by returning a pointer to the element, which means that
// access operations require dereferencing the pointer.

#include <iostream> // for cout
#include <algorithm> // for fill(), copy()
#include <initializer_list> // for initializer_list<>

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
        : sz {s}, elem {new double[sz]}
    {
        std::fill(elem, elem + sz, 0.0);
    }

    // constructor that takes an initializer list
    // it creates a vector with a size equal to the number of elements in the
    // initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz {lst.size()}, elem {new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    // gets called when a vector is initialized from another vector
    // it sets this vector's size to the input vector's size and copies the
    // the values of the input vector's elements to this vector's elements
    vector(const vector& v)
        : sz {v.sz}, elem {new double[sz]}
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
    // provides read and write access to a vector by returning a pointer to
    // the element at index n
    // NOTE: function does not provide any range checking
    // HOWEVER: since this function returns a pointer, indexing operations
    // require dereferencing the pointer, ie:
    // cout << *v[i] << endl;
    // *v[i] = val;
    // while this works, it is clunky and error-prone
    double *operator[](size_t n) { return &elem[n]; }

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
    // build a vector of 10 elements
    vector v1(10);

    // works but is ugly and error-prone
    for (size_t i = 0; i < v1.size(); i++)
    {
        *v1[i] = ((1.1 * i) + 1.1); // assign value to vector element
        std::cout << *v1[i] << '\n'; // write result to stdout
    }

    return 0;
}

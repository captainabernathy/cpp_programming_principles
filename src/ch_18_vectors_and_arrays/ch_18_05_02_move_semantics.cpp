// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement a move constructor and a move assignment operator

#include <iostream> // for cout
#include <algorithm> // for fill(), copy()
#include <utility> // for move()
#include <initializer_list> // for initializer_list<>

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

public:
    // default constructor
    vector()
        : sz {0}, elem {nullptr} {  }

    // public member functions
    // explicit constructor
    // allocates memory for a vector of s doubles
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
    vector(vector const& v)
        : sz {v.sz}, elem {new double[sz]}
    {
        std::cout << "copy constructor" << '\n';
        std::copy(v.elem, v.elem + sz, elem);
    }

    // move constructor
    // makes it easy and cheap to to move around large vectors... so that we
    // do not need to deal with pointers or references to get large amounts
    // of information out of a function into a vector
    // gets called implicitly by the compiler when moving a large collection
    // of elements into a vector is more efficient than copying it
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector(vector&& a)
        : sz {a.sz}, elem {a.elem} // copies a's elements and size to this
                                   // vector
                                   // NOTE: new not used!!!
    {
        std::cout << "move constructor" << '\n';
        // make the input vector empty
        a.sz = 0;
        a.elem = nullptr;
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    vector& operator=(vector const& v);

    // move assignment operator
    // gets called by the compiler when moving a large collection of elements
    // into a vector is more efficient than copying them to it by assignment
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector& operator=(vector&& a);

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: returning a reference facilitates conventional indexing
    // operations for vectors
    // HOWEVER: certain indexing operations will fail for constant vectors since
    // reading from a constant is supported but writing to a constant is illegal
    double& operator[](size_t idx) { return elem[idx]; }

    // member access operator for constant vectors
    // provides read access to a vector by returning the value of the
    // element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: this function is allowed because it returns a value, as
    // opposed to a reference
    double operator[](size_t idx) const { return elem[idx]; }

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of a vector
    size_t size() const { return sz; }
};


// copy assignment
vector& vector::operator=(vector const& rhs)
{
    std::cout << "copy assignment" << '\n';
    double *p = new double[rhs.sz]; // allocate new space
    
    // copy elements from rhs into p
    std::copy(rhs.elem, rhs.elem + rhs.sz, p);
    delete[] elem; // deallocate space allocated for this vector's elements
    
    elem = p; // set this vector's element pointer to p
    sz = rhs.sz; // update this vector's size
    
    return *this; // return self-reference
}

// move assignment
vector& vector::operator=(vector&& a)
{
    std::cout << "move assignment" << '\n';
    delete[] elem; // deallocate space allocated for this vector's elements

    elem = a.elem; // copy a's elements to this vector's element
    sz = a.sz; // update size
    
    // 'empty vector a'
    a.elem = nullptr;
    a.sz = 0;
    
    return *this; // return reference
}

// function that returns the vector it receives... contrived example to
// demonstrate move assignment when u = f(v)
vector f(vector& v);

// function that returns the vector it receives... contrived example to
// demonstrate copy assignment when u = g(v)
vector& g(vector& v);

int main()
{
    // build a vector from an initializer list
    vector v1 {1.1, 2.2, 3.3};
    
    // build vector via copy constructor
    vector v2(v1);

    // build vector via default constructor
    vector v3;
    // update vector via copy assignment
    v3 = v2;
    
    // build vector via move constructor... explicty (for example)
    vector v4(std::move(v3));

    // build vector via default constructor
    vector v5;
    // update vector via move assignment... explicitly (for example)
    v5 = std::move(v4);

    // build vector via default constructor
    vector v6;
    v6 = f(v5); // move assignment
   
    v2 = g(v3); // copy assignment

    return 0;
}

vector f(vector &v)
{
    return v;
}

vector& g(vector &v)
{
    return v;
}

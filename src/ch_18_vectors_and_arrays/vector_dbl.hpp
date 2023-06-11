#ifndef VECTOR_DBL_CLASS_HPP
#define VECTOR_DBL_CLASS_HPP

#include <cstddef> // for size_t
#include <algorithm> // for fill(), copy()
#include <initializer_list> // for initializer_list<>

// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
#include <iostream> // for cout
#endif

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elems; // pointer to elements in a vector

    // copy elements from v into *elems
    // void copy(vector const& v)
    // {
    //     // for (size_t i = 0; i < v.sz; i++)
    //     //     elems[i] = v.elems[i];
    //     std::copy(v.elems, v.elems + sz, elems);
    // }

public:
    // default constructor
    vector()
        : sz {0},
         elems {nullptr}
    {
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
        std::cout << "default constructor\n";
#endif
    }

    // public member functions
    // explicit constructor
    // allocates memory for a vector of s doubles
    explicit vector(size_t s)
        : sz {s},
          elems {new double[sz]}
    {
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
        std::cout << "explicit constructor\n";
#endif
        std::fill(elems, elems + sz, 0.0);
    }

    // returns the size of a vector
    size_t size() const
    {
        return sz;
    }

    // destructor deallocates dynamically allocated memory
    ~vector()
    {
        delete[] elems;
    }

// only defined when the member access operator is not supported
#ifdef GET_AND_SET
    // provides read access to this vector by returning the value
    // of the element at index n
    // NOTE: function does not provide any range checking
    double get(size_t n) const
    {
        return elems[n];
    }

    // provides write access to this vector by assigning double v to the
    // element at index n
    // NOTE: function does not provide any range checking
    void set(size_t n, double v)
    {
        elems[n] = v;
    }
#endif
    
// not defined when initializer list constructor is supported
#ifndef NO_INIT
    // constructor that takes an initializer list
    // it creates a vector with a size equal to the number of elements in the
    // initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz {lst.size()},
          elems {new double[sz]}
    {
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
        std::cout << "initializer list constructor\n";
#endif
        std::copy(lst.begin(), lst.end(), elems);
    }
#endif

// not defined when copy constructor is supported
#ifndef NO_COPY
    // copy constructor
    // gets called when a vector is initialized from another vector
    // it sets this vector's size to the input vector's size and copies the
    // the values of the input vector's elements to this vector's elements
    vector(vector const& v)
        : sz {v.sz},
          elems {new double[sz]}
    {
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
        std::cout << "copy constructor\n";
#endif
        std::copy(v.elems, v.elems + sz, elems);
    }
#endif

// not defined when move constructor is enabled
#ifndef NO_MOVE
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
        : sz {a.sz},
          elems {a.elems} // copies a's elements and size to this vector
                          // NOTE: new not used!!!
    {
// only defined when print debugging is enabled
#ifdef PRINT_DEBUG
        std::cout << "move constructor\n";
#endif
        // make the input vector empty
        a.sz = 0;
        a.elems = nullptr;
    }
#endif

// not defined when copy assignment is enabled
#ifndef NO_ASSIGN
    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    vector& operator=(vector const& v);
#endif

// not defined when move assignment operator is enabled
#ifndef NO_MOVE
    // move assignment operator
    // gets called by the compiler when moving a large collection of elements
    // into a vector is more efficient than copying them to it by assignment
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector& operator=(vector&& a);
#endif

// not defined when the member access operator is supported
#ifndef NO_ACCESS
    // member access operator
// only defined when the version of the member access operator that returns
// a double by value is supported
#ifdef READ_ONLY
    // provides read access to a vector by returning the value of the element
    // at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: this function only supports reading from a vector...
    // it DOES NOTE support assignment, so expressions of the form...
    // v[i] = val;
    // fail bc v[i] is not an lvalue
    double operator[](size_t n)
// only defined when the pointer version of the member access operator is
// supported
#elif defined READ_WRITE_PTR
    // provides read and write access to a vector by returning a pointer to
    // the element at index n
    // NOTE: function does not provide any range checking
    // HOWEVER: since this function returns a pointer, indexing operations
    // require dereferencing the pointer, ie:
    // cout << *v[i] << endl;
    // *v[i] = val;
    // while this works, it is clunky and error-prone
    double *operator[](size_t n)
#else
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: returning a reference facilitates conventional
    // indexing operations for vectors
    // HOWEVER: certain indexing operations will fail for constant vectors
    // since reading from a constant is supported but writing to a constant is
    // illegal
    double& operator[](size_t n)
#endif
    {
// only defined when the pointer version of the member access operator is
// supported
#ifdef READ_WRITE_PTR
        return &elems[n];
#else
        return elems[n];
#endif
    }
#endif

// not defined when the member access operator for constant vectors is
// supported
#ifndef NO_CONST
    // member access operator for constant vectors
    // provides read access to a vector by returning the value of the
    // element at index n
    // NOTE: function does not provide any range checking
    // MORE IMPORTANTLY: this function is allowed because it returns a value,
    // as opposed to a reference
    double operator[](size_t n) const
    {
        return elems[n];
    }
#endif

};

#endif

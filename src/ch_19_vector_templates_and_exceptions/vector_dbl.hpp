#ifndef VECTOR_DBL_HPP
#define VECTOR_DBL_HPP

#include <cstddef> // for size_t
#include <algorithm> // for fill(), copy()

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elems; // address of first element in a vector

    // total amout of space allocated for elements in a vector
    // number of elements + free space... sz + free space
    size_t cap;

public:
    // public member functions
    // default constructor, sets a vector's size and capacity to 0 and the
    // pointer to its elements to null
    vector()
        : sz {0}, elems {nullptr}, cap {0} {  }

    // deallocates a vector's dynamically allocated resources
    ~vector()
    {
        delete[] elems;
    }

    // returns the number of elements in a vector
    size_t size() const
    {
        return sz;
    }

    // returns the total number of spaces allocated for elements in a vector
    size_t capacity() const
    {
        return cap;
    }

// not defined when reserve() method is supported
#ifndef NO_RESERVE
    // reserves space for rsvp number of elements in a vector, and
    // updates the vector's capacity to rsvp
    // NOTE: when to_reserve does not exceed the currently allocated amount of
    // space for a vector's elements, the vector remains unchanged
    void reserve(size_t rsvp);
#endif

// not defined when resize() method is supported
#ifndef NO_RESIZE
    // resizes a vector to have new_size number of elements, initializes
    // each new element to 0.0, and updates the vector's size to new_size
    void resize(size_t new_size);
#endif

// not defined when explicit constructor, initializer list constructor,
// copy constructor, move constructor, copy assignment operator,
// move assignment operator, member access operator, and push_back() method
// are enabled
#ifndef NO_PUSH_BACK
    // explicit constructor
    // allocates memory for a vector of n doubles and sets its size and capacity
    // to n
    explicit vector(size_t n)
        : sz {n}, elems {new double[sz]}, cap {sz}
    {
        std::fill(elems, elems + sz, 0.0);
    }

    // initializer list constructor
    // creates a vector with a size and capacity equal to the number of elements
    // in the initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz {lst.size()}, elems {new double[sz]}, cap {sz}
    {
        std::copy(lst.begin(), lst.end(), elems);
    }

    // copy constructor... copy all parts of v!!!
    // gets called when a vector is initialized from another vector
    // it sets this vector's size and capacity to the size and capacity of
    // the input vector and copies the values of the input vectors elements
    // to this vector's elements
    vector(vector const& v)
        : sz {v.sz}, elems {new double[sz]}, cap {sz}
    {
        std::copy(v.elems, v.elems + sz, elems);
    }

    // move constructor... move all parts of v!!!
    // gets called implicitly by the compiler when moving a large collection
    // of elements into a vector is more efficient than copying
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify thier input and
    // make it 'empty'
    vector(vector&& v)
        : sz {v.sz}, elems {v.elems}, cap {sz}
    {
        v.sz = v.cap = 0;
        v.elems = nullptr;
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    // NOTE: if the capacity of rhs does not exceed the capacity of this vector,
    // then this vector's capacity remains unchanged
    vector& operator=(vector const& rhs);

    // move assignment operator
    // gets called by the compiler when moving a large collection of elements
    // into a vector is more efficient than copying them to it by assignment
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector& operator=(vector&& rhs);

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index i
    // NOTE: function does not provide any range checking
    double& operator[](size_t i)
    {
        return elems[i];
    }

    // member access operator for constant vectors
    // provides read access to a vector by returning the value of the
    // element at index i
    // NOTE: function does not provide any range checking
    double operator[](size_t i) const
    {
        return elems[i];
    }

    // initializes a new element at the end of a vector to d and
    // increases the vector's size by one
    void push_back(double d);
#endif
    
};

#endif

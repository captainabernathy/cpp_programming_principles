#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template
using namespace std;

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
        : sz{0}, elem{nullptr}, cap{0} {  }

    // explicit, one-argument constructor
    // allocates memory for a vector of n doubles and sets its size and capacity
    // to n
    explicit vector(size_t n)
        : sz{n}, elem{new double[n]}, cap{n}
    {
        std::fill(elem, elem + sz, 0.0);
    }

    // initializer list constructor
    // creates a vector with a size and capacity equal to the number of elements
    // in the initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz{lst.size()}, elem{new double[sz]}, cap{sz}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor... copy all parts of v!!!
    // gets called when a vector is initialized from another vector
    // it sets this vector's size and capacity to the size and capacity of
    // the input vector and copies the values of the input vectors elements
    // to this vector's elements
    vector(const vector& v)
        : sz{v.sz}, elem{new double[sz]}, cap{v.cap}
    {
        std::copy(v.elem, v.elem + sz, elem);
    }

    // move constructor... move all parts of v!!!
    // gets called implicitly by the compiler when moving a large collection
    // of elements into a vector is more efficient than copying
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify thier input and
    // make it 'empty'
    vector(vector&& v)
        : sz{v.sz}, elem{v.elem}, cap{v.cap} // NOTE: new not used
    {
        // make input vector empty
        v.sz = 0;
        v.cap = 0;
        v.elem = nullptr;
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    // NOTE: if the capacity of rhs does not exceed the capacity of this vector,
    // then this vector's capacity remains unchanged
    vector& operator=(const vector& rhs);

    // move assignment operator
    // gets called by the compiler when moving a large collection of elements
    // into a vector is more efficient than copying them to it by assignment
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector& operator=(vector&& rhs);

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    double& operator[](int idx) { return elem[idx]; }

    // member access operator for constant vectors
    // provides read access to a vector by returning the value of the
    // element at index n
    // NOTE: function does not provide any range checking
    double operator[](int idx) const { return elem[idx]; }

    // deallocates a vector's dynamically allocated resources
    ~vector() { delete[] elem; }

    // returns the number of elements in a vector
    size_t size() const { return sz; }

    // returns the total number of spaces allocated for elements in a vector
    size_t capacity() const { return cap; }

    // reserves space for rsvp number of elements in a vector, and
    // updates the vector's capacity to rsvp
    // NOTE: when to_reserve does not exceed the currently allocated amount of
    // space for a vector's elements, the vector remains unchanged
    void reserve(size_t rsvp);

    // resizes a vector to have new_size number of elements, initializes
    // each new element to 0.0, and updates the vector's size to new_size
    void resize(size_t new_size);

    // initializes a new element at the end of a vector to d and
    // increases the vector's size by one
    void push_back(double d);
};

// copy assignment
vector& vector::operator=(const vector& rhs)
{
    if (this == &rhs)
        return *this; // avoid self assignment

    if (rhs.sz <= cap) // don't need to allocate new space
    {
        // copy the elements from rhs to this vector's elements
        std::copy(rhs.elem, rhs.elem + rhs.sz, elem);
        sz = rhs.sz; // update this vector's size
        return *this; // return self-reference
    }

    double *d = new double[rhs.sz]; // allocate new space

    // copy the elements from rhs to the new space
    std::copy(rhs.elem, rhs.elem + rhs.sz, d);
    delete[] elem; // deallocate space allocated for this vector's elements

    elem = d; // set this vector's element pointer to d
    cap = sz = rhs.sz; // update this vector's capacity and size

    return *this; // return self-reference
}

// move assignment
vector& vector::operator=(vector&& rhs)
{

    if (this == &rhs)
        return *this; // avoid self assignment

    delete[] elem; // deallocate space allocated for this vector's elements
    sz = rhs.sz; // update this vector's size
    cap = rhs.cap;  // update this vector's capacity
    // set this vector's element pointer to rhs's element pointer
    elem = rhs.elem;

    // empty rhs
    rhs.elem = nullptr; // set rhs's element pointer to null
    rhs.sz = rhs.cap = 0; // set rhs's size and capacity to 0

    return *this; // return self-reference
}

void vector::reserve(size_t rsvp)
{
    if (rsvp <= cap)
        return ; // never decrease allocation

    double *d = new double[rsvp]; // allocate new space
    
    // copy the elements in this vector into the new space
    std::copy(elem, elem + sz, d);
    
    // deallocate the space previously allocated for this vector's elements
    delete[] elem;
    
    elem = d; // set this vector's element pointer to the new space
    cap = rsvp; // update this vector's capacity
}

// make this vector have new size elems... new elems initialized to 0.0
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

// add d to this vector at v.elem[sz]
void vector::push_back(double d)
{
    if (cap == 0) // when empty, reserve space for 8 elements
        reserve(8);
    else if (cap == sz) // when full, reserve space for 2X the capacity
        reserve(2 * cap);

    elem[sz] = d; // insert d to end of this vector
    sz++; // increase this vector's size
}

int main()
{
    vector v; // build a vector
    cout << "before reserve()..." << endl;
    cout << "v.size(): " << v.size() << endl; // 0
    cout << "v.capacity(): " << v.capacity() << endl; // 0
    cout << endl;

    v.push_back(7); // add an element to v
    cout << "after v.push_back(7)..." << endl;
    cout << "v.size(): " << v.size() << endl; // 1
    cout << "v.capacity(): " << v.capacity() << endl; // 8
    cout << "v[0]: " << v[0] << endl; // 7
    cout << endl;

    v.reserve(10); // reserve space for 10 elements in v
    cout << "after v.reserve(10)..." << endl;
    cout << "v.size(): " << v.size() << endl; // 1
    cout << "v.capacity(): " << v.capacity() << endl; // 10
    cout << endl;

    v.resize(4); // resize v
    cout << "after v.resize(4)..." << endl;
    cout << "v.size(): " << v.size() << endl; // 4
    cout << "v.capacity(): " << v.capacity() << endl; // 10

    return 0;
}

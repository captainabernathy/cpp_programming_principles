// program implements a template class that can be used to create a vector
// that contains elements of any type

#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template
#include <string> // string library header

// template for a vector parameterized by type T... a vector of type T elements
template<typename T>
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    T* elem; // address of the first element in a vector

    // total amout of space allocated for elements in a vector
    // number of elements + free space... sz + free space
    size_t cap;

public:
    // public member functions
    // default constructor, sets a vector's size and capacity to 0 and the
    // pointer to its elements to null
    vector()
        : sz{0}, elem{nullptr}, cap{0}
    { }

    // explicit, one-argument constructor
    // allocates memory for a vector of n Ts and sets its size and capacity
    // to n
    explicit vector(size_t n)
        : sz{n}, elem{new T[sz]}, cap{sz}
    {
        std::fill(elem, elem + sz, 0);
    }

    // initializer list constructor
    // creates a vector with a size and capacity equal to the number of elements
    // in the initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<T> lst)
        : sz{lst.size()}, elem{new T[sz]}, cap{sz}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor... copy all parts of v!!!
    // gets called when a vector is initialized from another vector
    // it sets this vector's size and capacity to the size and capacity of
    // the input vector and copies the values of the input vectors elements
    // to this vector's elements
    vector(vector const& v)
        : sz{v.sz}, elem{new T[sz]}, cap{sz}
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
        : sz{v.sz}, elem{v.elem}, cap{sz}
    {
        v.sz = v.cap = 0;
        v.elem = nullptr;
    }

    // deallocates a vector's dynamically allocated resources
    ~vector() { delete[] elem; }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    // NOTE: if the capacity of rhs does not exceed the capacity of this vector,
    // then this vector's capacity remains unchanged
    vector& operator=(vector const& rhs)
    {
        if (this == &rhs)
            return *this; // avoid self assignment

        if (rhs.cap <= cap) // don't need to allocate new space
        {
            // copy the elements from rhs to this vector's elements
            std::copy(rhs.elem, rhs.elem + rhs.sz, elem);
            sz = rhs.sz; // update this vector's size
            return *this; // return self-reference
        }

        T* t = new T[rhs.sz]; // allocate new space

        // copy the elements from rhs to the new space
        std::copy(rhs.elem, rhs.elem + rhs.sz, t);
        delete[] elem; // deallocate space allocated for this vector's elements
        
        elem = t; // set this vector's element pointer to t
        cap = sz = rhs.sz; // update this vector's capacity and size

        return *this; // return self-reference
    }

    // move assignment operator
    // gets called by the compiler when moving a large collection of elements
    // into a vector is more efficient than copying them to it by assignment
    // NOTE: && indicates an rvalue reference
    // move operations NEVER take const arguments as they modify their input and
    // make it 'empty'
    vector& operator=(vector&& rhs)
    {
        if (this == &rhs)
            return *this; // avoid self assignment

        delete[] elem; // deallocate space allocated for this vector's elements
        sz = cap = rhs.sz; // update this vector's size and capacity
        // set this vector's element pointer to rhs's element pointer
        elem = rhs.elem;

        // empty rhs
        rhs.elem = nullptr; // set rhs's element pointer to null
        rhs.sz = rhs.cap = 0; // set rhs's size and capacity to 0

        return *this; // return self-reference
    }

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    T& operator[](ssize_t idx) { return elem[idx]; }

    // member access operator for constant vectors
    // provides read access to a vector by returning a constant reference to the
    // element at index n
    // NOTE: function does not provide any range checking
    T const& operator[](ssize_t idx) const { return elem[idx]; }

    // returns the number of elements in a vector
    size_t size() const { return sz; }

    // returns the total number of spaces allocated for elements in a vector
    size_t capacity() const { return cap; }

    // reserves space for rsvp number of elements in a vector, and
    // updates the vector's capacity to rsvp
    // NOTE: when to_reserve does not exceed the currently allocated amount of
    // space for a vector's elements, the vector remains unchanged
    void reserve(size_t rsvp)
    {
        if (rsvp <= cap)
            return; // never decrease allocation

        T* t = new T[rsvp]; // allocate new space

        // copy the elements in this vector into the new space
        std::copy(elem, elem + sz, t);

        // deallocate the space previously allocated for this vector's elements
        delete[] elem;

        // set this vector's element pointer to the new t
        elem = t;
        cap = rsvp; // update this vector's capacity
    }

    // resizes a vector to have new_size number of elements, initializes
    // each new element to 0, and updates the vector's size to new_size
    void resize(size_t new_size)
    {
        // reserve space for new_size number of elements in this vector
        reserve(new_size);
        // set elements in this vector between (elem + sz) and (elem + new_size)
        // to 0...
        // including (elem + sz) but not (elem + new_size)
        std::fill(elem + sz, elem + new_size, 0);

        sz = new_size; // update this vector's size
    }

    // initializes a new element at the end of a vector to t and
    // increases the vector's size by one
    void push_back(T const& t)
    {
        if (cap == 0) // when empty, reserve space for 8 elems
            reserve(8);
        else if (cap == sz) // when full, reserve space for 2X
            reserve(2 * cap);

        elem[sz] = t; // insert t at the end of this vector
        sz++; // increase this vector's size
    }

    // void print(const std::string& s)
    // {
    //     for (size_t i = 0; i < sz; i++)
    //         std::cout << s << "[" << i << "]: " << elem[i] << std::endl;
    // }
};

// template for a function that prints an index-able collection of type T
// prepended by string s... works for any index-able collection that has a size
// function
template<typename T>
void print(T const& t, std::string const& s)
{
    for (size_t i = 0; i < t.size(); i++)
        std::cout << s << "[" << i << "]: " << t[i] << std::endl;
}

using std::cout;
using std::endl;

int main()
{
    vector<int> v1{1, 2, 3, 4}; // initializer list
    cout << "v1.size(): " << v1.size() << endl; // 4
    cout << "v1.capacity(): " << v1.capacity() << endl; // 4
    print(v1, "v1"); // output v1
    cout << endl;

    vector<int> v2(v1); // copy constructor
    cout << "v2.size(): " << v2.size() << endl; // 4
    cout << "v2.capacity(): " << v2.capacity() << endl; // 4
    print(v2, "v2"); // output v2
    cout << endl;

    vector<int> v3;
    v3 = v2; // copy assignment
    cout << "v3.size(): " << v3.size() << endl; // 4
    cout << "v3.capacity(): " << v3.capacity() << endl; // 4
    print(v3, "v3"); // output v3
    cout << endl;

    vector<int> vm1(v3); // copy constructor
    // NOTE: vm1 is 'emptied' by the move operation
    vector<int> v4(std::move(vm1)); // move constructor
    cout << "v4.size(): " << v4.size() << endl; // 4
    cout << "v4.capacity(): " << v4.capacity() << endl; // 4
    print(v4, "v4"); // output v4
    cout << endl;

    vector<int> v5; // default constructor
    vm1 = v4; // copy assignment
    v5 = std::move(vm1); // move assignment
    cout << "v5.size(): " << v5.size() << endl; // 4
    cout << "v5.capacity(): " << v5.capacity() << endl; // 4
    print(v5, "v5"); // output v5
    cout << endl;

    vector<int> v6; // default constructor
    // fill v6 using push_back()
    for (size_t i = 0; i < 4; i++)
    {
        v6.push_back(v1[i]);
        v6.push_back(v2[i] * (i + 1));
        v6.push_back(v3[i] * (i + 2));
        v6.push_back(v4[i] * (i + 3));
        v6.push_back(v5[i] * (i + 4));
    }

    cout << "v6.size(): " << v6.size() << endl; // 20
    cout << "v6.capacity(): " << v6.capacity() << endl; // 32
    print(v6, "v6"); // output v6
    cout << endl;

    const vector<int> v7(v5); // copy constructor
    cout << "v7.size(): " << v7.size() << endl; // 4
    cout << "v7.capacity(): " << v7.capacity() << endl; // 4
    print(v7, "v7"); // output v7
    cout << endl;
    
    int i = v7[3];
    const int j = v7[3];
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;

    return 0;
}

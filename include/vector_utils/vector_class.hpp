#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include <algorithm> // for copy(), fill()
#include <initializer_list> // for initializer_list<>

// not defined when vector<T,A> needed
#ifndef VECTOR_T
#include <memory> // for allocator
#endif

// not defined when vector<T,A> needed
#ifndef VECTOR_T
template<typename T, typename A = std::allocator<T>>
#else
template<typename T>
#endif
class vector {
public:
    // typedef size_t size_type;
    using size_type = std::size_t;

    // typedef ssize_t ssize_type;
    // using ssize_type = ssize_t;

    // typedef T value_type;
    using value_type = T;

    // typedef T* iterator;
    using iterator = T*;

    // typedef const T* const_iterator;
    using const_iterator = T const*;

    // default constructor
    // constructs an empty vector
    vector()
        : sz {0}, cap {0}, elems {nullptr}
    {  }

    // explicit constructor
    // constructs a vector of type T with size n, capacity n, and initializes
    // each of the vector's n elements to T()
    explicit vector(size_type n)
        : sz {n},
          cap {n},
// not defined when vector<T,A> needed
#ifndef VECTOR_T
          elems {alloc.allocate(n)}
#else
          elems {new T[sz]}
#endif
    {
// not defined when vector<T,A> needed
#ifndef VECTOR_T
        for (size_type i = 0; i < sz; i++)
            alloc.construct(&elems[i], T());
#else
        std::fill(elems, elems + sz, T());
#endif
    }

    // initializer list constructor
    // constructs a vector from a list of elements...
    // the vector's type will be of the same type as the elements in the list...
    // the vector's size and capacity will be the same as the size of the list..
    // the vector's elements will contain the same values as those of the list
    vector(std::initializer_list<T> lst)
        : sz {lst.size()},
          cap {sz},
// not defined when vector<T,A> needed
#ifndef VECTOR_T
          elems {alloc.allocate(sz)}
#else
          elems {new T[sz]}
#endif
    {
        std::copy(lst.begin(), lst.end(), elems);
    }

    // copy constructor
    // constructs a vector whose elements are copied from the vector received
    // and whose size and capacity are equal to the number of elements copied
    vector(vector const& v)
        : sz {v.sz},
          cap {sz},
// not defined when vector<T,A> needed
#ifndef VECTOR_T
          elems {alloc.allocate(sz)}
#else
          elems {new T[sz]}
#endif
    {
// not defined when vector<T,A> needed
#ifndef VECTOR_T
        for (size_type i = 0; i < sz; i++)
            alloc.construct(&elems[i], v.elems[i]);
#else
        std::copy(v.elems, v.elems + sz, elems);
#endif
    }

    // move constructor
    // constructs a vector direclty from the resources of vector received
    // whose size and capacity are equal to the size of the vector received and
    // whose elements are the same as those from the vector received...
    // the received vector is subsequently left in such a state that its size
    // and capacity are 0 and its elements are NULL
    vector(vector&& v)
        : sz {v.sz},
          cap {v.cap},
          elems {v.elems}
    {
        v.sz = v.cap = 0;
        v.elems = nullptr;
    }

    // destructor
    // releases the resources occupied by a vector
    ~vector()
    {
// not defined when vector<T,A> needed
#ifndef VECTOR_T
        // invalidate this vector's elements
        for (size_type i = 0; i < sz; i++)
            alloc.destroy(&elems[i]);

        // deallocate space previously allocated for this vector
        alloc.deallocate(elems, cap);
#else
        delete[] elems;
#endif
    }

    // copy assignment operator
    // overwrites this vector's elements with a copy of the elements contained
    // in the vector rhs and updates this vector's size and capacity to the
    // size of the elements in rhs provided that the capacity of rhs exceeds
    // this vector's capacity...
    // in the case that the capacity of this vector exceeds the capacity of rhs,
    // only the size of this vector is updated while its capacity remains
    // unchanged
    vector& operator=(vector const& rhs);

    // move assignment operator
    // directly assigns this vector's elements to the elements of rhs and
    // updates this vector's size and capacity to the size of and capacity of
    // rhs subsequently, the size and capacity of rhs will be 0, and its
    // elements will be NULL
    vector& operator=(vector&& rhs);

    // member access operator invoked by non-const vectors
    // returns reference to the element of this vector at index idx
    T& operator[](size_type idx)
    {
        return elems[idx];
    }

    // member access operator invoked by const vectors
    // returns a constant reference to the element of this vector at index idx
    T const& operator[](size_type idx) const
    {
        return elems[idx];
    }

    // returns the size of this vector
    size_type size() const
    {
        return sz;
    }

    // returns the capacity of this vector
    size_type capacity() const
    {
        return cap;
    }

    // reserves space for rsvp elements in this vector provided that rsvp is
    // greater than this vector's current capacity... does nothing when rsvp is
    // less than or equal to this vector's current capacity
    void reserve(size_type rsvp);

    // resizes this vector to new_size and initializes new elements to val
    // provided that new_size is greater than this vector's current size
    // new elements are added to the end of this vector
    // when new_size is less than this vector's current size the existing
    // elements in this vector that exceed new_size are invalidated
    void resize(size_type new_size, T val = T());

    // inserts t at the end of this vector and updates this vector's size
    void push_back(T const& t);

// not defined when vector<T,A> needed
#ifndef VECTOR_T
    // returns an iterator to the first element in this vector
    iterator begin()
    {
        return elems;
    }


    // returns a const interator to the first element in this vector
    const_iterator begin() const
    {
        return elems;
    }

    // returns an iterator to one past the last element in this vector
    iterator end()
    {
        return elems + sz;
    }

    // returns a const iterator to one past the last element in this vector
    const_iterator end() const
    {
        return elems + sz;
    }

    // returns a reference to the last element in this vector
    T& back()
    {
        return elems[sz - 1];
    }

    // inserts val before the element at p in this vector and returns an
    // iterator to the newly inserted element
    iterator insert(iterator p, T const& val);
    
    // removes the element at position p in this vector and returns a pointer
    // to the element after p
    iterator erase(iterator p);
#endif

private:
// not defined when vector<T,A> needed
#ifndef VECTOR_T
    A alloc;
#endif
    size_type sz;
    size_type cap;
    T *elems;
};

#endif

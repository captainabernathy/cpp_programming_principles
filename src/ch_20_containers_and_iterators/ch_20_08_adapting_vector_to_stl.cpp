// program implements a template class for a vector of any type

#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template
#include <memory> // provides utilities for managing dynamic memory
#include <string> // string library header
// #include <iterator> // iterator library header

template<typename T, typename A = std::allocator<T>>
class vector {
    A alloc;
    size_t sz;
    size_t cap;
    T *elems;

public:
    using size_type = std::size_t;
    // typedef size_t size_type;
    using ssize_type = ssize_t;
    // typedef ssize_t ssize_type;
    using value_type = T;
    // typedef T value_type;
    using iterator = T*;
    // typedef T* iterator;
    using const_iterator = T const*;
    // typedef const T* const_iterator;

    // default constructor
    // constructs an empty vector
    vector()
        : sz {0}, cap {0}, elems {nullptr}
    {  }

    // single argument constructor
    // constructs a vector of type T with size n, capacity n, and initializes
    // each of the vector's n elements to T()
    explicit vector(size_type n)
        : sz {n}, cap {n}, elems {alloc.allocate(n)}
    {
        for (size_type i = 0; i < sz; i++)
            alloc.construct(&elems[i], T());
    }

    // initializer list constructor
    // constructs a vector from a list of elements...
    // the vector's type will be of the same type as the elements in the list...
    // the vector's size and capacity will be the same as the size of the list..
    // the vector's elements will contain the same values as those of the list
    vector(std::initializer_list<T> lst)
        : sz {lst.size()}, cap {sz}, elems {alloc.allocate(sz)}
    {
        std::copy(lst.begin(), lst.end(), elems);
    }

    // copy constructor
    // constructs a vector whose elements are copied from the vector received
    // and whose size and capacity are equal to the number of elements copied
    vector(vector const& v)
        : sz {v.sz}, cap {sz}, elems {alloc.allocate(sz)}
    {
        for (size_type i = 0; i < sz; i++)
            alloc.construct(&elems[i], v.elems[i]);
    }

    // move constructor
    // constructs a vector direclty from the resources of vector received
    // whose size and capacity are equal to the size of the vector received and
    // whose elements are the same as those from the vector received...
    // the received vector is subsequently left in such a state that its size
    // and capacity are 0 and its elements are NULL
    vector(vector&& v)
        : sz {v.sz}, cap {v.cap}, elems {v.elems}
    {
        v.sz = v.cap = 0;
        v.elems = nullptr;
    }

    // destructor
    // releases the resources occupied by a vector
    ~vector()
    {
        // invalidate this vector's elements
        for (size_type i = 0; i < sz; i++)
            alloc.destroy(&elems[i]);

        // deallocate space previously allocated for this vector
        alloc.deallocate(elems, cap);
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

    // member access operator invoked by non-const objects
    // returns reference to the element of this vector at index idx
    T& operator[](ssize_type idx)
    {
        return elems[idx];
    }

    // member access operator invoked by const objects
    // returns a constant reference to the element of this vector at index idx
    T const& operator[](ssize_type idx) const
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

    // resizes this vector to new_size and initializes new elements to val provided
    // that new_size is greater than this vector's current size
    // new elements are added to the end of this vector
    // when new_size is less than this vector's current size the existing elements
    // in this vector that exceed new_size are invalidated
    void resize(size_type new_size, T val = T());

    void push_back(T const& t);

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

    // inserts val before the element at p in this vector and returns an iterator
    // to the newly inserted element
    iterator insert(iterator p, T const& val);
    
    // removes the element at position p in this vector and returns a pointer to
    // the element after p
    iterator erase(iterator p);
};

// reserves space for rsvp elements in this vector provided that rsvp is
// greater than this vector's current capacity... does nothing when rsvp is
// less than or equal to this vector's current capacity
template<typename T, typename A>
void vector<T,A>::reserve(size_type rsvp)
{
    if (rsvp <= cap)
        return ; // don't decrease allocation

    T *t = alloc.allocate(rsvp); // allocate new space
    
    // uses existing elements to construct elements in new space
    for (size_type i = 0; i < sz; i++)
        alloc.construct(&t[i], elems[i]);

    // destroy elements in old space
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);

    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);
    elems = t; // update elements
    cap = rsvp; // update capacity
}

// resizes this vector to new_size and initializes new elements to val provided
// that new_size is greater than this vector's current size
// new elements are added to the end of this vector
// when new_size is less than this vector's current size the existing elements
// in this vector that exceed new_size are invalidated
template<typename T, typename A>
void vector<T,A>::resize(size_type new_size, T val)
{
    reserve(new_size); // make space for new elemens

    // loop runs when there's space to fill at the end of this vector
    for (size_type i = sz; i < new_size; i++)
        alloc.construct(&elems[i], val); // initialize newly added elements

    // loop runs when this vector's size exceeds new_size
    for (size_type i = new_size; i < sz; i++)
        alloc.destroy(&elems[i]);  // invalidate old elements

    sz = new_size; // update size
}

// inserts t at the end of this vector and updates this vector's size
template<typename T, typename A>
void vector<T,A>::push_back(T const& t)
{
    if (cap == 0)  // reserve space for 8 elements when this vector is empty
        reserve(8);
    else if (sz == cap)   // reserve space for twice as many element when this
        reserve(2 * cap); // vector is full

    alloc.construct(&elems[sz], t); // insert t at the end of this vector
    sz++; // update this vector's size
}

// overwrites this vector's elements with a copy of the elements contained
// in the vector rhs and updates this vector's size and capacity to the
// size of the elements in rhs provided that the capacity of rhs exceeds
// this vector's capacity...
// in the case that the capacity of this vector exceeds the capacity of rhs,
// only the size of this vector is updated while its capacity remains
// unchanged
template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector const& rhs)
{
    if (this == &rhs) // short circuit when rhs already refers to this vector
        return *this;

    // when there's no need to allocate more space in this vector
    if (rhs.cap <= cap)
    {
        // copy up to rhs.sz elements from rhs into this vector at the same
        // corresponding position
        for (size_type i = 0; i < rhs.sz; i++)
            alloc.construct(&elems[i], rhs.elems[i]);

        // invalidate any elements in this vector that exceed the size of rhs
        for (size_type i = rhs.sz; i < sz; i++)
            alloc.destroy(&elems[i]);

        sz = rhs.sz; // update size
        return *this;
    }

    // allocate space for rhs.sz elements
    T *t = alloc.allocate(rhs.sz);

    // fill newely allocated space with the elements in rhs
    for (size_type i = 0; i < rhs.sz; i++)
        alloc.construct(&t[i], rhs.elems[i]);

    // invalidate this vector's elements
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);
    
    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);

    cap = sz = rhs.sz; // update size and capacity
    elems = t; // update this vectors elements
    return *this;
}

// move assignment operator
// directly assigns this vector's elements to the elements of rhs and updates
// this vector's size and capacity to the size of and capacity of rhs
// subsequently, the size and capacity of rhs will be 0, and its elements
// will be NULL
template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& rhs)
{
    if (this == &rhs)  // short circuit when rhs already refers to this vector
        return *this;

    // invalidate all of this vector's elements
    for (size_type i = 0; i < sz; i++)
        alloc.destroy(&elems[i]);

    // deallocate space previously allocated for this vector
    alloc.deallocate(elems, cap);

    sz = rhs.sz; // update size
    cap = rhs.cap; // update capacity
    elems = rhs.elems; // update this vector's elements
    rhs.elems = nullptr; // set rhs's elements to NULL
    rhs.sz = rhs.cap = 0; // set rhs's size and capacity to 0

    return *this;
}

// inserts val before the element at p in this vector and returns an iterator
// to the newly inserted element
template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, T const& val)
{
    size_type idx = p - begin();
    if (size() == capacity())
        reserve(size() == 0 ? 8 : 2 * size()); // make sure we have space

    // first, copy last element into unitialized space
    alloc.construct(elems + sz, back());
    ++sz; // update size
    
    iterator pp = begin() + idx; // the place to put the value

    // copy the elements from the last element up (down) to pp one position to
    // the right
    for (iterator pos = end() - 1; pos != pp; --pos)
        *pos = *(pos - 1); // copy elements one position to the right

    *(begin() + idx) = val; // insert val
    
    return pp; // return iterator to val
}

// removes the element at position p in this vector and returns a pointer to
// the element after p
template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
    if (p == end())  // nothing to delete here
        return p;

    // copy the elements after p to the end of this array one position to the
    // left
    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos; // copy elements one position to left

    // destroy/invalidate surplus copy of last element
    alloc.destroy(&*(end() - 1));
    --sz; // update size
    return p;
}

int main()
{
    using std::cout;

    vector<int> v1{1, 2, 3, 4};
    v1.insert(v1.end(), 99);
    v1.erase(v1.end() - 2);
    for (auto v : v1)
        cout << v << ' ';
    cout << '\n';
    cout << v1.size() << " " << v1.capacity() << "\n\n";

    vector<int> v2(v1);
    for (auto v : v2)
        cout << v << ' ';
    cout << '\n';
    cout << v2.size() << " " << v2.capacity() << "\n\n";

    vector<int> v3 = v2;
    for (auto v : v3)
        cout << v << ' ';
    cout << '\n';
    cout << v3.size() << " " << v3.capacity() << "\n\n";

    vector<int> v4;
    v4 = v3;
    for (auto v : v4)
        cout << v << ' ';
    cout << '\n';
    cout << v4.size() << " " << v4.capacity() << "\n\n";

    vector<int> v5(std::move(v1));
    for (auto v : v5)
        cout << v << ' ';
    cout << '\n';
    cout << v5.size() << " " << v5.capacity() << "\n\n";

    v5.push_back(18);
    for (auto v : v5)
        cout << v << ' ';
    cout << '\n';
    cout << v5.size() << " " << v5.capacity() << "\n\n";
    
    vector<int> v6 = std::move(v5);
    for (auto v : v6)
        cout << v << ' ';
    cout << '\n';
    cout << v6.size() << " " << v6.capacity() << "\n\n";

    vector<int> v7;
    v7 = std::move(v6);
    for (auto v : v7)
        cout << v << ' ';
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n";

    v7 = v4;
    for (auto v : v7)
        cout << v << ' ';
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n";

    vector<int>::iterator i = v7.begin();
    ++i;
    ++i;

    vector<int>::iterator j = i;
    ++j;

    cout << *i << " " << v7[2] << " " << *j << "\n\n";

    i = v7.erase(i);
    for (auto v : v7)
        cout << v << ' ';
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << '\n';
    cout << *i << "\n\n";

    vector<int>::iterator k = v7.begin();
    ++k;

    k = v7.insert(k, 13);
    for (auto v : v7)
        cout << v << ' ';
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << '\n';
    cout << *k << "\n\n";

    v7[2] = v2[3];
    for (auto v : v7)
        cout << v << ' ';
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n";

    const vector<int> v8(v7);

    for (size_t i = 0; i < v8.size(); i++)
        cout << v8[i] << ' ';
    cout << '\n';
    cout << v8.size() << " " << v8.capacity() << "\n\n";

    const int ci = v8[2];
    const int &cr  = v8[3];
    const int *p = &v8[0];
    cout << ci << " " << cr << " " << *p << '\n';

    return 0;
}

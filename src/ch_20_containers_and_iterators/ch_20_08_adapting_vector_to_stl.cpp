#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template
#include <memory> // provides utilities for managing dynamic memory
#include <string> // string library header
#include <iterator> // iterator library header

template<typename T, typename A = std::allocator<T>>
class vector {
    A alloc;
    size_t sz;
    size_t cap;
    T *elem;

public:
    typedef size_t size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;

    // default constructor
    vector()
        : sz{0}, cap{0}, elem{nullptr}
    {  }

    // single argument constructor
    explicit vector(size_t n)
        : sz{n}, cap{n}, elem{alloc.allocate(n)}, cap{n}
    {
        for (size_t i = 0; i < sz; i++)
            alloc.construct(&elem[i], T());
    }

    // initializer list constructor
    vector(std::initializer_list<T> lst)
        : sz{lst.size()}, cap{sz}, elem{alloc.allocate(sz)}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    vector(const vector& v)
        : sz{v.sz}, cap{sz}, elem{alloc.allocate(sz)}
    {
        for (size_t i = 0; i < sz; i++)
            alloc.construct(&elem[i], v.elem[i]);
    }

    // move constructor
    vector(vector&& v)
        : sz{v.sz}, cap{sz}, elem{v.elem}
    {
        v.sz = v.cap = 0;
        v.elem = nullptr;
    }

    // destructor
    ~vector()
    {
        for (size_t i = 0; i < sz; i++)
            alloc.destroy(&elem[i]);
        alloc.deallocate(elem, sz);
    }

    // assignment operator
    vector& operator=(const vector& rhs);

    // move assignment
    vector& operator=(vector&& rhs);

    // access... invoked by non-const objects... returns reference
    T& operator[](ssize_t idx)
    {
        return elem[idx];
    }

    // access... invoked by const objects... returns value
    T operator[](ssize_t idx) const
    {
        return elem[idx];
    }

    size_type size() const
    {
        return sz;
    }

    size_type capacity() const
    {
        return cap;
    }

    // add free space to end of this object update cap to rsvp
    void reserve(size_t rsvp);

    void resize(size_t new_size, T val = T());

    void push_back(const T& t);

    iterator begin()
    {
        return elem;
    }

    // ???
    const_iterator begin() const
    {
        return elem;
    }

    // ???
    iterator end()
    {
        return elem + sz;
    }

    // ???
    const_iterator end() const
    {
        return elem + sz;
    }

    // ???
    T& back()
    {
        return elem[sz - 1];
    }

    iterator insert(iterator p, const T& val);
    iterator erase(iterator p);
};

template<typename T, typename A>
void vector<T,A>::push_back(const T& t)
{
    if (cap == 0)
        reserve(8);
    else if (sz == cap)
        reserve(2 * cap);

    alloc.construct(&elem[sz], t);
    sz++;
}

template<typename T, typename A>
void vector<T,A>::resize(size_t new_size, T val)
{
    reserve(new_size);

    for (size_t i = sz; i < new_size; i++)
        alloc.construct(&elem[i], val);

    for (size_t i = new_size; i < sz; i++)
        alloc.destroy(&elem[i]);

    sz = new_size;
}

template<typename T, typename A>
void vector<T,A>::reserve(size_t rsvp)
{
    if (rsvp <= cap)
        return ; // don't decrease allocation

    T *t = alloc.allocate(rsvp);
    for (size_t i = 0; i < sz; i++)
        alloc.construct(&t[i], elem[i]);
    for (size_t i = 0; i < sz; i++)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, cap);
    elem = t;
    cap = rsvp;
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector& rhs)
{
    if (this == &rhs)
        return *this;

    if (rhs.cap <= cap) // don't need new allocation
    {
        for (size_t i = 0; i < rhs.sz; i++)
            alloc.construct(&elem[i], rhs.elem[i]);
        sz = rhs.sz;
        return *this;
    }

    T *t = alloc.allocate(rhs.sz);
    for (size_t i = 0; i < rhs.sz; i++)
        alloc.construct(&t[i], rhs.elem[i]);

    for (size_t i = 0; i < sz; i++)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, sz);

    cap = sz = rhs.sz;
    elem = t;
    return *this;
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& rhs)
{
    if (this == &rhs)
        return *this;

    for (size_t i = 0; i < sz; i++)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, sz);
    sz = cap = rhs.sz;
    elem = rhs.elem;
    rhs.elem = nullptr;
    rhs.sz = rhs.cap = 0;
    return *this;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
    size_t idx = p - begin();
    if (size() == capacity())
        reserve(2 * size()); // make sure we have space

    // first copy last element into unitialized space
    alloc.construct(elem + sz, back());
    ++sz;
    iterator pp = begin() + idx; // place to put the value
    for (iterator pos = end() - 1; pos != pp; --pos)
        *pos = *(pos - 1); // copy elements one position to the right
    *(begin() + idx) = val;
    return pp;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
    if (p == end())
        return p;

    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos; // copy elements one position to left
    alloc.destroy(&*(end() - 1)); // destroy surplus copy of last element
    --sz;
    return p;
}

using std::cout;
using std::endl;

int main()
{
    vector<int> v1{1, 2, 3, 4};
    v1.insert(v1.end(), 99);
    v1.erase(v1.end() - 2);
    for (auto v : v1)
        cout << v << endl;

    // for (vector<int>::iterator v = v1.begin(); v != v1.end(); ++v)


    return 0;
}

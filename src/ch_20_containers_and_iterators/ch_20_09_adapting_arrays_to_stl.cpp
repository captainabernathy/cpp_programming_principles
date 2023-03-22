// program implements a template class for an array of any type

#include <iostream> // I/O library header
using namespace std;

template<typename T, size_t N>
struct array {
    using size_type = size_t;
    // typedef size_t size_type;
    using value_type = T;
    // typedef T value_type;
    using iterator = T*;
    // typedef T* iterator;
    using const_iterator = T const*;
    // typedef const T* const_iterator;

    T elems[N]; // no explicit construct/copy/destroy needed

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
        return elems + N;
    }

    // returns a const iterator to one past the last element in this vector
    size_type size() const;

    // member access operator invoked by non-const objects
    // returns reference to the element of this array at index n
    T& operator[](ssize_t n)
    {
        return elems[n];
    }

    // member access operator invoked by const objects
    // returns a constant reference to the element of this array at index n
    const T& operator[](ssize_t n) const
    {
        return elems[n];
    }

    // provides range-checked access to this array
    // invoked by const objects
    // returns a constant reference to the element of this array at index n
    const T& at(ssize_t n) const;  // NOT IMPLEMENTED
   
    // provides range-checked access to this array
    // invoked by non-const objects
    // returns a reference to the element of this array at index n
    T& at(ssize_t n); // NOT IMPLEMENTED

    // returns a pointer to the first element of this array
    // invoked by non-const objects
    T *data()
    {
        return elems;
    }

    // returns const pointer to the first element of this array
    // invoked by const objects
    const T *data() const
    {
        return elems;
    }
};

// template function that takes an iterator to a range of elements in a
// collection... [first,last)... and returns an iterator that points to the
// largest element in the range
template<typename T>
T high(T first, T last)
{
    T high = first; // assume first is the largest
    for (T t = first; t != last; t++) // loop over collection
        if (*high < *t) // update largest if necessary
            high = t;
    return high; // return pointer to largest element in range
}

void f()
{
    array<double, 6> a = {0.0, 1.1, 2.2, 99.9, 4.4, 5.5};
    array<double, 6>::iterator p = high(a.begin(), a.end());
    cout << "the highest value was " << *p << endl;
}

int main()
{
    f();
    return 0;
}

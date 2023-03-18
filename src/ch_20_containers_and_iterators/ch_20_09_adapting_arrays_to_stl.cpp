#include <iostream> // I/O library header
using namespace std;

template<typename T, size_t N>
struct array {
    typedef size_t size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;

    T elems[N];
    // no explicit construct/copy/destroy needed

    iterator begin()
    {
        return elems;
    }

    const_iterator begin() const
    {
        return elems;
    }

    iterator end()
    {
        return elems + N;
    }

    size_type size() const;

    T& operator[](ssize_t n)
    {
        return elems[n];
    }

    const T& operator[](ssize_t n) const
    {
        return elems[n];
    }

    const T& at(ssize_t n) const; // ranged-checked access
    T& at(ssize_t n); // range-checked access

    T *data()
    {
        return elems;
    }

    const T *data() const
    {
        return elems;
    }
};

template<typename T>
T high(T first, T last)
{
    T high = first;
    for (T t = first; t != last; t++)
        if (*high < *t)
            high = t;
    return high;
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

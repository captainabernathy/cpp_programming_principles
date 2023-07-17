#ifndef ARRAY_REF_HPP
#define ARRAY_REF_HPP

#include <cstddef> // for size_t

// an interface to a class that can be used to approximate a reference to a
// built-in array...  it neither owns, nor allocates, nor deletes any
// object(s)... it simply references an existing array
template<typename T>
class Array_ref {
public:
    // constructor... initializes this Array_ref's element pointer to p
    // and this Array_ref's size to s
    Array_ref(T *p, size_t s)
        : ptr {p}, sz {s} {  }

#ifndef NO_ARRAY_REF_CALL_OPERATOR
    // conversion operator that converts this Array_ref of type T to an
    // Array_ref of type U
    //
    // NOTE: since this conversion uses reinterpret_cast<>, NEVER use an
    // Array_ref conversion from a class using multiple inheritance
    template<typename U>
    operator const Array_ref<const U>()
    {
        // check for implicit conversion of elements
        sizeof(static_cast<U>(*static_cast<T*>(nullptr)));

        // build (and return) a new Array_ref<const U> via the brute-force
        // reinterpret_cast<> to get a pointer to the desired element type
        return Array_ref<const U>(reinterpret_cast<U*>(ptr), sz);
    }
#endif

    // member access operator...
    // returns a refrence to the element at index n of this Array_ref
    T& operator[](size_t n)
    {
        return ptr[n];
    }

    // member access operator... for constant Array_refs
    // returns a constant refrence to the element at index n of this Array_ref
    T const& operator[](size_t n) const
    {
        return ptr[n];
    }

    // assigns each of the elements in the Array_ref ar to corresponding
    // positions in this Array_ref and returns true upon success
    //
    // NOTE: if this Array_ref and ar differ in size, then the method will
    // return false and no elements will be copied
    bool assign(Array_ref ar)
    {
        if (ar.sz != sz) // if sizes differ return false
            return false;

        // loop over elements in ar and copy them to the same position in this
        // Array_ref
        for (size_t i = 0; i < sz; ++i)
            ptr[i] = ar.ptr[i];

        return true;
    }

    // sets the pointer to this Array_ref's elements to the pointer to ar's
    // elements and sets the size of this Array_ref to the size of ar
    void reset(Array_ref ar)
    {
        reset(ar.ptr, ar.sz);
    }

    // sets the pointer to this Array_ref's elements to p and this Array_ref's
    // size to s
    void reset(T *p, size_t s)
    {
        ptr = p;
        sz = s;
    }

    // returns the size (number of elements) in this Array_ref
    size_t size() const
    {
        return sz;
    }

private:
    T *ptr; // pointer to this Array_ref's elements
    size_t sz; // the number of elements in this Array_ref
};

#endif

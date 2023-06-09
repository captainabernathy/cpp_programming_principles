#ifndef LARGER_THAN_HPP
#define LARGER_THAN_HPP

// class template for a function object that returns true when the object
// passed to it is larger than the object used to instantiate it
template<typename T>
class Larger_than {
    T v; // private data member

public:
    // constructor initializes val
    Larger_than(T val)
        : v {val}
    {  }
    
    // overloaded function call operator intercepts calls to this object
    // returns true if x is greater than this object's v
    bool operator()(T x)
    {
        return x > v;
    }
};

#endif

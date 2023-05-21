// program implements an ad-hoc vector class that can be used to create
// a vector of doubles and demonstrates its usage

#include <iostream> // for cout

// simple class to represent vector of doubles
// provides a constructor, destructor, get(), set(), and size() methods
class vector {
    // private members
    size_t sz; // size
    double *elem; // pointer to the elements

public:
    // constructor
    // creates a new vector of s elements
    explicit vector(size_t s)
        : sz {s}, elem {new double[s]} {  }

    // destructor
    ~vector()
    {
        delete[] elem; // release dynamically allocated resources
    }

    // returns the number elements in this vector
    size_t size() const
    {
        return sz; // current size
    }

    // access: read
    // returns the nth element in this vector
    double get(size_t n) const
    {
        return elem[n];
    }

    // access: write
    // sets the nth element in this vector to v
    void set(size_t n, double v)
    {
        elem[n] = v;
    }
};

int main()
{
    vector v(5); // build a vector

    for (size_t i = 0; i < v.size(); i++)
    {
        v.set(i, 1.1 + i); // populate elements of v
        // write value of each element in v to stdout
        std::cout << "v[" << i << "]: " << v.get(i) << '\n';
    }

    return 0;
}

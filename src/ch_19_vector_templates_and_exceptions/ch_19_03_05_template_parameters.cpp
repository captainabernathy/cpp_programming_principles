// program implements a template for a structure that can be used to create
// N element arrays of any type

#include <iostream> // I/O library header
#include <vector> // vector library header
#include <string> // string library header

// template for an N element array of type T
template<typename T, size_t N>
struct array {
    T elem[N]; // N element array of type T

    // rely on default constructors, destructor, and assignment

    // member access operator
    // provides read and write access to an array  by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    T& operator[](ssize_t n) { return elem[n]; }

    // member access operator for constant arrays
    // provides read access to an array by returning a constant reference to the
    // element at index n
    // NOTE: function does not provide any range checking
    T const& operator[](ssize_t n) const { return elem[n]; }

    // conversion to T*
    // returns a pointer to an array's elements
    // provides read/write access to an array's elements
    T* data() { return elem; }

    // returns a const pointer to an array's elements
    // provides read access to an array's elements
    const T* data() const { return elem; }

    // returns the number of elements in an array
    size_t size() const { return N; }
};

// template for a function that fills an N element array of type T (array<T,N>)
// with the value of type T provied to val
template<typename T, size_t N>
void fill(array<T, N>& arr, T const& val)
{
    for (size_t i = 0; i < N; i++)
        arr[i] = val;
}

// void f(size_t n)
// {
//     array<char, n> arr; // error: value of n not know to compiler
// }

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
using std::vector;

int main()
{
    array<int, 5> ai = {1, 2, 3, 4, 5}; // 5 element array of integers
    print(ai, "ai"); // output ai
    cout << endl;

    int *ap = ai.data(); // get pointer to ai's elements
    // print(ap, "ap"); // ap has no size() function

    ap[3] = 3 * 3; // changes ai
    print(ai, "ai"); // output ai
    cout << endl;

    ai[3] += 3; // change ai directly
    print(ai, "ai"); // output ai
    cout << endl;

    vector<int> vi{6, 7, 8, 9, 10}; // vector of 5 integers
    print(vi, "vi"); // works... vi has a size() method

    return 0;
}

// program implements a template for a class that can be used to create
// N element arrays of any type
//
// program also implements a funtion template to print the elements of any
// index-able collection that has a size() function, as well as an overloaded
// implementation that prints the first n elements of any index-able collection
// that provides a size() function

#include <iostream> // for cout
#include <vector> // for vector
#include <string> // for string

// template for an N element array of type T
template<typename T, size_t N>
struct array {
    T elem[N]; // N element array of type T

    // rely on default constructors, destructor, and assignment

    // member access operator
    // provides read and write access to an array  by returning a reference to
    // the element at index n
    // NOTE: function does not provide any range checking
    T& operator[](size_t n) { return elem[n]; }

    // member access operator for constant arrays
    // provides read access to an array by returning a constant reference to the
    // element at index n
    // NOTE: function does not provide any range checking
    T const& operator[](size_t n) const { return elem[n]; }

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
template<typename T, size_t n>
void fill(array<T, n>& arr, T const& val)
{
    for (size_t i = 0; i < n; i++)
        arr[i] = val;
}

// template for a function that prints an index-able collection of type T
// prepended by string s... works for any index-able collection that has a size
// function
template<typename T>
void print(T const& t, std::string const& s)
{
    for (size_t i = 0; i < t.size(); i++)
        std::cout << s << "[" << i << "]: " << t[i] << '\n';
}

// template for a function that prints the first n elements of an index-able
// collection of type T prepended by string s
// NOTE: function does not provide any range checking
template<typename T>
void print(T const& t, size_t n, std::string const& s)
{
    for (size_t i = 0; i < n; i++)
        std::cout << s << "[" << i << "]: " << t[i] << '\n';
}

int main()
{
    using std::cout;
    using std::vector;

    array<int, 5> ai1 {1, 2, 3, 4, 5}; // 5 element array of integers

    print(ai1, "ai1"); // output ai1
    cout << '\n';

    int *ap1 = ai1.data(); // get pointer to ai1's elements

    print(ap1, ai1.size(), "ap1"); // output ap1
    cout << '\n';

    array<int, 5> ai2; // 5 element array of integers
    fill(ai2, 75); // fill ai2's elements with 75

    print(ai2, "ai2"); // output ai2
    cout << '\n';

    fill(ai1, 33); // fill ai1's elements with 33

    print(ai1, "ai1"); // output ai1
    cout << '\n';

    print(ap1, ai1.size(), "ap1"); // output ap1... will be 33

    return 0;
}

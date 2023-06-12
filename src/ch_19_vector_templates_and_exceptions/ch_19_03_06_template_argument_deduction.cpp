// program tests the implementation of a class template for an array that can
// store N elements of any type
//
// program also tests the implementation of the function template print<>()
// that can print the elements of any index-able collection that has a size()
// function, as well as an overloaded version of print<>() than can print
// the first n elements of any index-able collection that provides a size()
// function
//
// <typename T, size_t N>
// array (template class)
//      size_t size() const
//      T* data()
//      T const* data() const
//
// <typename T, size_t N>
// void fill(array<T,N>& arr, T const& val)
//
// template<typename T>
// void print(T const& t, string const& s)
//
// template<typename T>
// void print(T const& t, size_t n, string const& s)

#include <iostream> // for cout
#include <vector> // for vector
#include <array_utils/array_utils.hpp> // for array, fill<>()
#include "collection_utils.hpp" // for print<>()

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

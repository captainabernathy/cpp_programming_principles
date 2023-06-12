// program tests the implementation of a class template for an array that can
// store N elements of any type
//
// <typename T, size_t N>
// array (template class)
//      T& operator[](size_t n)
//      T const& operator[](size_t n) const
//      T* data()
//      T const* data() const
//
// template<typename T>
// void print(T const& t, string const& s)

#include <iostream> // for cout
#include <vector> // for vector
#include <array_utils/array_utils.hpp> // for array
#include "collection_utils.hpp" // for print<>()

// inline void f(size_t n)
// {
//     array<char, n> arr; // error: value of n not know to compiler
// }

int main()
{
    using std::vector;
    using std::cout;

    array<int, 5> ai {1, 2, 3, 4, 5}; // 5 element array of integers

    print(ai, "ai"); // output ai
    cout << '\n';

    int *ap = ai.data(); // get pointer to ai's elements
    // print(ap, "ap"); // ap has no size() function

    ap[3] = 3 * 3; // changes ai

    print(ai, "ai"); // output ai
    cout << '\n';

    ai[3] += 3; // change ai directly

    print(ai, "ai"); // output ai
    cout << '\n';

    vector<int> vi {6, 7, 8, 9, 10}; // vector of 5 integers

    print(vi, "vi"); // works... vi has a size() method

    return 0;
}

// program tests the implementation of a class template for an array that can
// store N elements of any type
//
// program also uses the array template to test the function template high<>()
//
// <typename T, size_t N>
// array (template class)
//      iterator begin()
//      iterator end()
//
// template<typename T>
// T high(T first, T last)

#include <iostream> // cout
#include <array_utils/array_utils.hpp> // for array
#include "high.hpp" // for high<>()

inline void f()
{
    array<double, 6> a = {0.0, 1.1, 2.2, 99.9, 4.4, 5.5};
    array<double, 6>::iterator p = high(a.begin(), a.end());
    std::cout << "the highest value was " << *p << '\n';
}

int main()
{
    f();

    return 0;
}

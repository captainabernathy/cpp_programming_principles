// program tests the implementation of the function template accumulate<>() to
// accumulate the sum of the elements in a collection between two iterators
// using a specified value as the starting point for the computation
//
// template<typename Iter, typename T>
// T accumulate(Iter first, Iter last, T start)

#include <iostream> // for cout
#include <algorithm_utils/accumulate.hpp> // for accumulate<>()

int main()
{
    using std::cout;

    int arr[5] = {1, 2, 3, 4, 5};
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << accumulate(arr, arr + 5, 0) << '\n';
    cout << accumulate(d, d + 5, 0.0) << '\n';

    return 0;
}

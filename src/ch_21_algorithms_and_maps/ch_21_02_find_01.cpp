// program tests the implementation of the function template find<>() to find
// an element between a pair of iterators into a collection
//
// Iter find<Iter, T>(Iter first, Iter last, T const& val)

#include <vector>  // for vector
#include <iostream> // for cout
#include <algorithm_utils/find.hpp> // for find<>()

// function tests the the function template find() by using it to determine
// if the integer x exists within the vector v references
void f(std::vector<int>& v, int x);

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = arr;
    int *last = arr + 7;

    std::vector<int> v(first, last);
    f(v, 4);

    return 0;
}

// function tests the the function template find() by using it to determine
// if the integer x exists within the vector v references
void f(std::vector<int>& v, int x)
{
    std::vector<int>::iterator p = find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

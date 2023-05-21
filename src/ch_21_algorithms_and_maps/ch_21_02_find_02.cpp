// program implements a function template to find an integer between a pair
// of iterators to a collection

#include <iostream> // for cout
#include <vector>  // for vector

// function template that finds the first element between the iterators
// first and last (range [first,last)) that is equal to val and returns and
// returns an iterator to it...
// if val is not found the iterator returned will be equal to last
// this implementation is less efficient that the version in
// ch_21_02_find_01.cpp
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
    for (Iter p = first; p != last; ++p)
        if (*p == val) // test predicate
            return p;
    return last;
}

// function tests the the function template find() by using it to determine
// if the integer x exists within the vector v references
void f(std::vector<int>& v, int x);

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = arr;
    int *last = arr + 7;

    std::vector<int> v(first, last);
    f(v, 5);

    return 0;
}

void f(std::vector<int>& v, int x)
{
    std::vector<int>::iterator p = find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

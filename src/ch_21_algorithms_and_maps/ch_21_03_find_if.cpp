// program tests the implementation of the function template find_if<>() to
// find an element between a pair of iterators into a collection that satisfies
// a predicate function
//
// template<typename Iter, typename Pred>
// Iter find_if(Iter first, Iter last, Pred pred)

#include <vector>  // for vector
#include <list> // for list
#include <iostream> // for cout
#include <algorithm_utils/find_if.hpp> // for find_if<>()

double v; // global double

// returns true if x is an odd number, false if x is even
inline bool odd(int x)
{
    return x % 2;
}

// returns true if x is greater than 42, false if x is not
inline bool larger_than_42(double x)
{
    return x > 42.0;
}

// returns true if x is greater than the global variable v, false if x is not
inline bool larger_than_v(double x)
{
    return x > v;
}

// function that tests the find_if() function on a vector of integers to find
// the first odd number in the vector
void f(std::vector<int>&);

// function that tests the find_if() function on a list of doubles to find
// the first element in the list greater than 42
void f(std::list<double>&);

// function that tests the find_if() function on a list of doubles to find
// the first double greater than x
void f(std::list<double>&, double x);

int main()
{
    {
        int arr[7] = {10, 20, 30, 41, 50, 60, 70};
        int *first = arr;
        int *last = arr + 7;
        std::vector<int> v(first, last);
        f(v);
    }

    {
        double arr[7] = {1.1, 2.2, 3.3, 4.4, 55, 6.6, 7.7};
        double *first = arr;
        double *last = arr + 7;
        std::list<double> l(first, last);
        f(l);
        f(l, 4);
    }

    return 0;
}

// function that tests the find_if() function on a vector of integers to find
// the first odd number in the vector
void f(std::vector<int>& v)
{
    std::vector<int>::iterator p = find_if(v.begin(), v.end(), odd);
    if (p != v.end())
        std::cout << "Found odd number: " << *p << '\n';
    else
        std::cout << "Did not find an odd number\n";
}

// function that tests the find_if() function on a list of doubles to find
// the first element in the list greater than 42
void f(std::list<double>& v)
{
    std::list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_42);
    if (p != v.end())
        std::cout << *p << " is larger than 42\n";
    else
        std::cout << "Did not find a number larger than 42\n";
}

// function that tests the find_if() function on a list of doubles to find
// the first double greater than x
void f(std::list<double>& v, double x)
{
    ::v = 3.1; // set global v to 31
    std::list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_v);
    if (p != v.end())
        std::cout << *p << " is larger than " << ::v << '\n';
    else
        std::cout << "Did not find a number larger than " << ::v << '\n';

    ::v = x;
    std::list<double>::iterator q = find_if(v.begin(), v.end(), larger_than_v);
    if (q != v.end())
        std::cout << *q << " is larger than " << ::v << '\n';
    else
        std::cout << "Did not find a number larger than " << ::v << '\n';

}

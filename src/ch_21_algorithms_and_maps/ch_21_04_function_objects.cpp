// program tests the implementation of the function template find_if<>() to
// find an element between a pair of iterators into a collection that satisfies
// a predicate function
//
// program also tests the implementation the class template Larger_than<>,
// which provides a function object that can be used as a predicate function
//
// template<typename Iter, typename Pred>
// Iter find_if(Iter first, Iter last, Pred pred)
//
// template<typename T>
// Larger_than (template class)
//      Larger_than(T val)
//      bool operator()(T x)

#include <list> // for list
#include <iostream> // for cout
#include <algorithm_utils/find_if.hpp> // for find_if<>()
#include "larger_than.hpp" // for Larger_than<>

// function that tests the find_if<>() function template and the Larger_than<>
// function object template
void f(std::list<double>&, double);

int main()
{
    double arr[7] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7};
    double *first = arr;
    double *last = arr + 7;
    std::list<double> v(first, last);
    f(v, 55.6);

    // lambda expression becomes the the function object passed to pred
    std::cout << *(find_if(v.begin(), v.end(),
                   [](double a){return a > 72.3;})) << '\n';

    return 0;
}

// function that tests the find_if<>() function template and the Larger_than<>
// function object template
void f(std::list<double>& v, double d)
{
    std::list<double>::iterator p = find_if(v.begin(), v.end(),
                                            Larger_than<double> {31.2});

    if (p != v.end())
        std::cout << *p << " is larger than " << 31.2 << '\n';
    else
        std::cout << "Did not find a value larger than 31.2\n";

    std::list<double>::iterator q = find_if(v.begin(), v.end(),
                                            Larger_than<double> {d});

    if (q != v.end())
        std::cout << *q << " is larger than " << d << '\n';
    else
        std::cout << "Did not find a value larger than " << d << '\n';
}

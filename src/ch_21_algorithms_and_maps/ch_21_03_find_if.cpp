// program implements and tests a template function that returns the first
// element in a collection between two iterators that satisfies a predicate
// function

#include <list> // list library header
#include <iostream> // I/O library header
#include <vector>  // vector library header
using namespace std;

// template function that returns the first element in a collection between
// the iterators first and last (range [first,last)) that satisfies the
// predicate function pred and returns an iterator to it
// if no element satisfies the predicate function the iterator returned will be
// equal to last
template<typename Iter, typename Pred>
Iter find_if(Iter first, Iter last, Pred pred)
{
    while (!(first == last || pred(*first)))
        ++first; // advance to next position in collection
    return first;
}

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

// function that tests the find_if() function on a vector of integers to find
// the first odd number in the vector
void f(vector<int>&);

// function that tests the find_if() function on a list of doubles to find
// the first element in the list greater than 42
void f(list<double>&);

double v; // global double

// returns true if x is greater than the global variable v, false if x is not
inline bool larger_than_v(double x)
{
    return x > v;
}

// function that tests the find_if() function on a list of doubles to find
// the first double greater than x
void f(list<double>&, double x);

int main()
{
    {
        int arr[7] = {10, 20, 30, 41, 50, 60, 70};
        int *first = arr;
        int *last = arr + 7;
        vector<int> v(first, last);
        f(v);
    }

    {
        double arr[7] = {1.1, 2.2, 3.3, 4.4, 55, 6.6, 7.7};
        double *first = arr;
        double *last = arr + 7;
        list<double> l(first, last);
        f(l);
        f(l, 4);
    }

    return 0;
}

void f(vector<int>& v)
{
    vector<int>::iterator p = find_if(v.begin(), v.end(), odd);
    if (p != v.end())
        cout << "Found odd number: " << *p << endl;
    else
        cout << "Did not find an odd number" << endl;
}

void f(list<double>& v)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_42);
    if (p != v.end())
        cout << *p << " is larger than 42" << endl;
    else
        cout << "Did not find a number larger than 42" << endl;
}

void f(list<double>& v, double x)
{
    ::v = 3.1; // set global v to 31
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_v);
    if (p != v.end())
        cout << *p << " is larger than " << ::v << endl;
    else
        cout << "Did not find a number larger than " << ::v << endl;

    ::v = x;
    list<double>::iterator q = find_if(v.begin(), v.end(), larger_than_v);
    if (q != v.end())
        cout << *q << " is larger than " << ::v << endl;
    else
        cout << "Did not find a number larger than " << ::v << endl;

}
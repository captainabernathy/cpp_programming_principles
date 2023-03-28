// program implements and tests a template function that returns the first
// element in a collection between two iterators that satisfies a predicate
// program also implements a template class for a function object that can be
// used a predicate with the template function

#include <iostream> // I/O library header
#include <list> // list library header
#include <vector> // vector library header
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

// template class for a function object that returns true when the object
// passed to it is larger than the object used to instantiate it
template<typename T>
class Larger_than {
    T v;
public:
    Larger_than(T val)
        : v{val} {  }
    
    // NOTE: to create a function object, overload the function call operator
    bool operator()(T x)
    {
        return x > v;
    }
};

// function that tests the template function and function object template
// implemented above
void f(list<double>&, double);

int main()
{
    double arr[7] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7};
    double *first = arr;
    double *last = arr + 7;
    list<double> v(first, last);
    f(v, 55.6);

    // lambda expression becomes the the function object passed to pred
    cout << *(find_if(v.begin(), v.end(),
                [](double a){return a > 72.3;})) << endl;

    return 0;
}

void f(list<double>& v, double d)
{
    list<double>::iterator p = find_if(v.begin(), v.end(),
                                        Larger_than<double>(31.2));

    if (p != v.end())
        cout << *p << " is larger than " << 31.2 << endl;
    else
        cout << "Did not find a value larger than 31.2" << endl;

    list<double>::iterator q = find_if(v.begin(), v.end(),
                                        Larger_than<double>(d));

    if (q != v.end())
        cout << *q << " is larger than " << d << endl;
    else
        cout << "Did not find a value larger than " << d << endl;
}
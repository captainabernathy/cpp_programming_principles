#include <list>
#include <vector>
#include <iostream>
using namespace std;

template<typename Iter, typename Pred>
Iter find_if(Iter first, Iter last, Pred pred)
{
    while (!(first == last || pred(*first)))
        ++first;
    return first;
}

inline bool odd(int x)
{
    return x % 2;
}

inline bool larger_than_42(double x)
{
    return x > 42;
}

void f(vector<int>&);
void f(list<double>&);

double v;
inline bool larger_than_v(double x)
{
    return x > v;
}

void f(list<double>&, double);

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

#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename Iter, typename Pred>
Iter find_if(Iter first, Iter last, Pred pred)
{
    while (!(first == last || pred(*first)))
        ++first;
    return first;
}

template<typename T>
class Larger_than {
    T v;
public:
    Larger_than(T val)
        : v{val} {  }
    bool operator()(T x)
    {
        return x > v;
    }
};

void f(list<double>&, double);

int main()
{
    double arr[7] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7};
    double *first = arr;
    double *last = arr + 7;
    list<double> v(first, last);
    f(v, 55.6);

    // lambda
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

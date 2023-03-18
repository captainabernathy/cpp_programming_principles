#include <iostream>
#include <vector>
using namespace std;

// less efficient that previous version
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
    for (Iter p = first; p != last; ++p)
        if (*p == val)
            return p;
    return last;
}

void f(vector<int>& v, int x);

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = arr;
    int *last = arr + 7;

    vector<int> v(first, last);
    f(v, 5);

    return 0;
}

void f(vector<int>& v, int x)
{
    vector<int>::iterator p = find(v.begin(), v.end(), x);
    if (p != v.end())
        cout << "Found: " << *p << endl;
    else
        cout << "Did not find: " << x << endl;
}

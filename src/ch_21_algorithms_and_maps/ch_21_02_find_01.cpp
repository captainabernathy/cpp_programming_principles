#include <iostream>
#include <vector>
using namespace std;

// find the first element in the [first, last) that equals val
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
    // while (first != last && *first != val)
    while (!(first == last || *first == val))
        ++first;
    return first;
}

void f(vector<int>& v, int x);

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = arr;
    int *last = arr + 7;

    vector<int> v(first, last);
    f(v, 4);

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

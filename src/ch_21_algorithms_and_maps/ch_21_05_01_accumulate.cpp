#include <iostream>
#include <vector>
using namespace std;

template<typename Iter, typename T>
T accumulate(Iter first, Iter last, T start)
{
    while (first != last)
    {
        start += *first;
        ++first;
    }

    return start;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << accumulate(arr, arr + 5, 0) << endl;
    cout << accumulate(d, d + 5, 0.0) << endl;

    return 0;
}

// program implements a template function to find an integer between a pair
// of iterators to a collection

#include <iostream> // I/O library header
#include <vector>  // vector library header
using namespace std;

// template function that finds the first element between the iterators
// first and last (range [first,last)) that is equal to val and returns and
// returns an iterator to it...
// if val is not found the iterator returned will be equal to last
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
    // while (first != last && *first != val)
    while (!(first == last || *first == val))
        ++first; // advance to next position in collection
    return first;
}

// function tests the the template function find() by using it to determine
// if the integer x exists within the vector v references
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
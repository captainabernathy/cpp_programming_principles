// program implements a function template that accumulates the sum of the
// elements in a collection between two iterators and uses a specified value
// as the starting point for the accumulation

#include <iostream> // for cout

// function template that accumulates and returns the sum of the elements in a
// collection between the iterators first and last (range [first,last)) using
// the value passed to start as the starting point for the accumulation
template<typename Iter, typename T>
T accumulate(Iter first, Iter last, T start)
{
    while (first != last)
    {
        start += *first; // accumulate results
        ++first; // advance to next position in collection
    }

    return start;
}

int main()
{
    using std::cout;

    int arr[5] = {1, 2, 3, 4, 5};
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << accumulate(arr, arr + 5, 0) << '\n';
    cout << accumulate(d, d + 5, 0.0) << '\n';

    return 0;
}

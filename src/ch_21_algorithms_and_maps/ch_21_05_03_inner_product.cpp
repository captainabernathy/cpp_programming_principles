// program implements a template function that computes the inner product of
// two collections using a specified value as the starting point of the
// computation

#include <iostream> // I/O library header
#include <list> // list library header
#include <vector> // vector library header
using namespace std;

// template function that returns the inner product of two collections using start
// as the starting point for accumulating the result
// the first collection consists of the range of elements between the iterators
// first1 and last1 (range [first1,last1)), and the second collection begins
// at the iterator first2
template<typename Iter1, typename Iter2, typename T>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start)
{
    while (first1 != last1)
    {
        start += (*first1 * *first2); // accumulate results

        // advance to next position in both collections
        ++first1;
        ++first2;
    }

    return start;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2(arr1);

    cout << inner_product(arr1.begin(), arr1.end(), arr2.begin(), 0) << endl
        << endl;

    vector<double> dow_price;
    dow_price.push_back(81.86);
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);

    list<double> dow_weight;
    dow_weight.push_back(5.8549);
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);

    double dji_index = inner_product(
            dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0);
    cout << "DJI value: " << dji_index << endl;

    return 0;
}

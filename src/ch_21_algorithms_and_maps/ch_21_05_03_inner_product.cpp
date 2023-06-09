// program tests the implementation of the function template inner_product<>()
// to compute the inner product of two collections using a specified value as
// the starting point of the computation
//
// T inner_product<It1, Iter2, T>(Iter1 first1, Iter1 last1, Iter2 first2,
//                                T start)

#include <vector> // for vector
#include <iostream> // for cout
#include <list> // for list
#include <algorithm_utils/inner_product.hpp> // for inner_product<>()

int main()
{
    using std::vector;
    using std::list;
    using std::cout;

    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2(arr1);

    cout << inner_product(arr1.begin(), arr1.end(), arr2.begin(), 0) << "\n\n";

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
    cout << "DJI value: " << dji_index << '\n';

    return 0;
}

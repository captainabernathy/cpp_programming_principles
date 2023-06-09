// program tests the implementation of the function template inner_product<>()
// to compute the inner product of two collections using a specified value as
// the starting point of the computation
//
// the computation is performed using two binary operations, such that the
// first operation is used to accumulate the results of successively applying
// the second operation to pairs of elements from each collection
//
// T inner_product<Iter1, Iter2, T, BinOp1, BinOp2>(Iter1 first1, Iter1 last1,
//                                                  Iter2 first2, T start,
//                                                  BinOp1 op1, BinOp2 op2)

#include <vector> // for vector
#include <iostream>  // cout
#include <functional> // for plus<>(), multiplies<>()
#include <list> // for list
#include <algorithm_utils/inner_product.hpp> // for inner_product<>()

int main()
{
    using std::vector;
    using std::list;
    using std::plus;
    using std::multiplies;
    using std::cout;

    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2(v1);
    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(),
                          multiplies<int>()) << '\n';

    vector<double> dow_price;
    dow_price.push_back(81.86);
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);

    list<double> dow_weight;
    dow_weight.push_back(5.8549);
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);

    double dji_index = inner_product(
            dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0,
            plus<double>(), multiplies<double>());
    cout << "DJI value: " << dji_index << '\n';

    return 0;
}

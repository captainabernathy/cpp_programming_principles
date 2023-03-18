#include <iostream>
#include <vector>
#include <list>
#include <functional>
using namespace std;

template<typename Iter1, typename Iter2, typename T, typename BinOp1,
         typename BinOp2>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start, BinOp1 op1,
                BinOp2 op2)
{
    while (first1 != last1)
    {
        start = op1(start, op2(*first1, *first2));
        ++first1;
        ++first2;
    }

    return start;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2(v1);
    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(),
                          multiplies<int>()) << endl;

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
    cout << "DJI value: " << dji_index << endl;

    return 0;
}

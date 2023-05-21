// program implements a function template that computes the inner product of
// two collections using a specified value as the starting point of the
// computation, one specifies binary operation to perfom the pairwise operation
// between the two collections, and another to accumulate the results

#include <iostream>  // cout
#include <vector> // for vector 
#include <list> // for list 
#include <functional> // for plus<>, multiplies<>

// function template that returns the inner product of two collections using
// start as the starting point for accumulating the result
// the first collection consists of the range of elements between the iterators
// first1 and last1 (range [first1,last1)), and the second
// collection begins at the iterator first2
// the binary operation op2 is successively applied to corresponding elements
// of the first and second collections, and the binary operation op1 is used
// to accumulate the results from op2
template<typename Iter1, typename Iter2, typename T, typename BinOp1,
         typename BinOp2>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start, BinOp1 op1,
                BinOp2 op2)
{
    while (first1 != last1)
    {
        // output of op2 becomes the second operand of op1
        start = op1(start, op2(*first1, *first2));

        // advance to next position in both collections
        ++first1;
        ++first2;
    }

    return start;
}

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

// program implements a template function that computes the inner product of
// two collections using a specified value as the starting point of the
// computation, one specified binary operation to perfom the pairwise operation
// between the two collections, and another to accumulate the results
//
// program implements a function to extract the product from two
// <string,double> pairs, and uses it with the inner product template function
// to compute the inner product of two map objects that contain the same keys

#include <iostream> // I/O library header
#include <map> // map library header
#include <string> // string library header
#include <utility> // provides pair class
using namespace std;

// template function that returns the inner product of two collections using
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

// NOTE: a pair object collects of two values that may be of different types
// and can be accessed via its public first and second members
//
// function returns the the product of the second members of a and b
double weighted_value(pair<string, double> const& a,
                      pair<string, double> const& b)
{
    return a.second * b.second;
}

int main()
{
    // (symbol, price) map
    map<string, double> dow_price;
    
    // insert into map via assignment
    dow_price["MMM"] = 81.86;
    dow_price["AA"] = 34.69;
    dow_price["MO"] = 54.45;

    // (symbol, weight) map
    map<string, double> dow_weight;

    // insert pairs into map via insert() method
    // NOTE: the make_pair() function is used to construct a pair object
    dow_weight.insert(make_pair("MMM", 5.8549));
    dow_weight.insert(make_pair("AA", 2.4808));
    dow_weight.insert(make_pair("MO", 3.8940));

    // (symbol, name) map
    map<string, string> dow_name;

    // insert into map via assignment
    dow_name["MMM"] = "3M Co.";
    dow_name["AA"] = "Alcoa Inc.";
    dow_name["MO"] = "Altria Group Inc.";

    // get values from map via direct access by key
    double alcoa_price = dow_price["AA"];
    double altria_price = dow_price["MO"];
    cout << "alcoa_price: " << alcoa_price << endl;
    cout << "altria_price: " << altria_price << endl << endl;

    // NOTE: a map object's find() method returns an iterator to an element
    // in a map that corresponds to the key provided
    // find entry in a map
    if (dow_price.find("INTC") != dow_price.end())
        cout << "Intel is in the Dow" << endl;

    if (dow_price.find("MMM") != dow_price.end())
        cout << "MMM is in the Dow" << endl;

    cout << endl;

    // iterate over map
    for (map<string, double>::const_iterator it = dow_price.begin();
         it != dow_price.end(); ++it)
    {
        string const& symbol = it->first;
        cout << symbol << "\t" << it->second << "\t" << dow_name[symbol]
            << endl;
    }
    cout << endl;

    // compute inner product from dow prices and weight using the plus function
    // for accumulation and the weighted_value for multiplication
    double dji_index = inner_product(dow_price.begin(), dow_price.end(),
            dow_weight.begin(), 0.0, plus<double>(), weighted_value);

    cout << "DJI value: " << dji_index << endl;

    return 0;
}
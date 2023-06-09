// program tests the implementation of the function template inner_product<>()
// to compute the inner product of two collections using a specified value as
// the starting point of the computation
//
// the computation is performed using two binary operations, such that the
// first operation is used to accumulate the results of successively applying
// the second operation to pairs of elements from each collection
//
// program also tests the implementation of the weighted_value() function,
// which extracts the product from a pair of <string,double> pairs
//
// the weighted_value() function is subsequently used in conjunction with the
// inner_product<>() function template to compute the inner product between
// two map objects that contain the same keys
//
// T inner_product<Iter1, Iter2, T, BinOp1, BinOp2>(Iter1 first1, Iter1 last1,
//                                                  Iter2 first2, T start,
//                                                  BinOp1 op1, BinOp2 op2)
//
// double weighted_value(pair<string, double> const& a,
//                       pair<string, double> const& b)

#include <map> // for map
#include <string> // for string
#include <utility> // for make_pair()
#include <iostream> // for cout
#include <functional> // for plus<>
#include <algorithm_utils/inner_product.hpp> // for inner_product<>()
#include "weighted_value.hpp" // for weighted_value()

int main()
{
    using std::map;
    using std::string;
    using std::make_pair;
    using std::plus;
    using std::cout;

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
    cout << "alcoa_price: " << alcoa_price << '\n';
    cout << "altria_price: " << altria_price << "\n\n";

    // NOTE: a map object's find() method returns an iterator to an element
    // in a map that corresponds to the key provided
    // find entry in a map
    if (dow_price.find("INTC") != dow_price.end())
        cout << "Intel is in the Dow\n";

    if (dow_price.find("MMM") != dow_price.end())
        cout << "MMM is in the Dow\n";

    cout << '\n';

    // iterate over map
    for (map<string, double>::const_iterator it = dow_price.begin();
         it != dow_price.end(); ++it)
    {
        string const& symbol = it->first;
        cout << symbol << '\t' << it->second << '\t' << dow_name[symbol]
            << '\n';
    }
    cout << '\n';

    // compute inner product from dow prices and weight using the plus<>
    // function object for accumulation and the weighted_value function
    // for multiplication
    double dji_index = inner_product(dow_price.begin(), dow_price.end(),
            dow_weight.begin(), 0.0, plus<double>(), weighted_value);

    cout << "DJI value: " << dji_index << '\n';

    return 0;
}

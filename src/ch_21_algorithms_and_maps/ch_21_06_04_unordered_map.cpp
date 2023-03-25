#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
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

inline double weighted_value(const pair<string, double>& a,
                             const pair<string, double>& b)
{
    return a.second * b.second;
}

int main()
{
    // (symbol, price) map
    unordered_map<string, double> dow_price;
    dow_price["MMM"] = 81.86;
    dow_price["AA"] = 34.69;
    dow_price["MO"] = 54.45;

    // (symbol, weight) map
    unordered_map<string, double> dow_weight;
    dow_weight.insert(make_pair("MMM", 5.8549));
    dow_weight.insert(make_pair("AA", 2.4808));
    dow_weight.insert(make_pair("MO", 3.8940));

    // (symbol, name) map
    unordered_map<string, string> dow_name;
    dow_name["MMM"] = "3M Co.";
    dow_name["AA"] = "Alcoa Inc.";
    dow_name["MO"] = "Altria Group Inc.";

    double alcoa_price = dow_price["AA"];
    double altria_price = dow_price["MO"];
    cout << "alcoa_price: " << alcoa_price << endl;
    cout << "altria_price: " << altria_price << endl << endl;

    // find entry in a map
    if (dow_price.find("INTC") != dow_price.end())
        cout << "Intel is in the Dow" << endl;

    if (dow_price.find("MMM") != dow_price.end())
        cout << "MMM is in the Dow" << endl;

    cout << endl;

    for (unordered_map<string, double>::const_iterator it = dow_price.begin();
         it != dow_price.end(); ++it)
    {
        const string& symbol = it->first;
        cout << symbol << "\t" << it->second << "\t" << dow_name[symbol]
            << endl;
    }
    cout << endl;

    double dji_index = inner_product(dow_price.begin(), dow_price.end(),
            dow_weight.begin(), 0.0, plus<double>(), weighted_value);

    cout << "DJI value: " << dji_index << endl;

    return 0;
}

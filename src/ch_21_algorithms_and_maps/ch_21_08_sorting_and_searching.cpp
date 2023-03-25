// program implements a function object for performing case-insensitive
// comparisons between strings
// program also implements a data structure for representing fruits and 
// provides a function object for performing comparisons between fruits
// program also demonstrates the use of the standard library equal_range()
// function, which returns a pair of iterators to the bounds of where a
// specified element is found in a collection

#include <algorithm> // algorithm library header
#include <iostream> // I/O library header
#include <string> // string library header
#include <vector> // vector library header
#include <utility> // provides pair class
using namespace std;

// data structure for a function object that performs a case-insensitive
// comparison between two strings
struct No_case {
    bool operator()(string const& x, string const& y) const
    {
        // loop over first string
        for (size_t i = 0; i < x.length(); i++)
        {
            if (i == y.length())
                return false; // y < x... (fewer characters in y)

            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx < yy)
                return true; // x < y
            if (yy < xx)
                return false; // y < x

        }

        if (x.length() == y.length())
            return false; // x == y

        return true; // x < y (fewer characters in x)
    }
};

// data structure that represents a fruit by a name
struct Fruit {
    string name;
    
    // initializes name to n
    Fruit(const char *n)
        : name{n}
    {  }
};

// data structure for a function object that can be used to compare Fruit
// objects
struct Fruit_order {
    bool operator()(Fruit const& a, Fruit const& b) const
    {
        return a.name < b.name;
    }
};

int main()
{
    vector<Fruit> vf;
    vf.push_back(Fruit("Apple"));
    vf.push_back(Fruit("Banana"));
    vf.push_back(Fruit("Watermelon"));
    vf.push_back(Fruit("Starfruit"));
    vf.push_back(Fruit("Lemon"));
    vf.push_back(Fruit("Lime"));
    vf.push_back(Fruit("Orange"));
    vf.push_back(Fruit("Pear"));
    vf.push_back(Fruit("Strawberry"));
    vf.push_back(Fruit("Grape"));
    vf.push_back(Fruit("Pear"));
   
    vector<Fruit> vf2(vf); // uses defalt copy constructor
    
    // sort using a lambda function as a basis for comparisons
    sort(vf.begin(), vf.end(),
            [](Fruit const& a, Fruit const& b){ return a.name < b.name; });

    for (auto it : vf)
        cout << it.name << endl;
    cout << endl;
    
    // sort using Fruit_order function object as a basis for comparisons
    sort(vf2.begin(), vf2.end(), Fruit_order());
    
    vector<string> vs;
    for (auto it: vf2)
    {
        vs.push_back(it.name);
        cout << it.name << endl;
    }
    cout << endl;

    // sort using No_case function object as a basis for comparisons
    sort(vs.begin(), vs.end(), No_case());

    for (auto it: vs)
        cout << it << endl;
    cout << endl;

    using FI = vector<Fruit>::iterator;
    // typedef vector<Fruit>::iterator FI;

    // NOTE: the equal_range() function returns a pair of iterators to the
    // lower and upper bound positions (range [lower,upper) in a collection
    // where its third argument is found between the iterators passed to its
    // first and second arguments (range [first,second)) based on the results
    // of the predicate passed to its fourth argument
    
    // pair of fruit iterators
    pair<FI, FI> ff = equal_range(vf.begin(), vf.end(), "Pear",
            [](const Fruit& a, const Fruit& b){ return a.name < b.name; });

    // results for the bounds on pair in vf
    cout << "bounds for " << ff.first->name << " begin at position "
        << (ff.first - vf.begin()) << " and end at position "
        << (ff.second - vf.begin()) << " with "
        << ff.second->name << endl << endl;

    // let the compiler determine the pair
    auto fp = equal_range(vf2.begin(), vf2.end(), "Pear", Fruit_order());
    
    // results for the bounds on pair in vf2
    cout << "bounds for " << fp.first->name << " begin at position "
        << (fp.first - vf2.begin()) << " and end at position "
        << (fp.second - vf2.begin()) << " with "
        << fp.second->name << endl << endl;

    auto sp = equal_range(vs.begin(), vs.end(), "Pear");

    // results for the bounds on pair in vs
    cout << "bounds for " << *sp.first << " begin at position "
        << (sp.first - vs.begin()) << " and end at position "
        << (sp.second - vs.begin()) << " with "
        << *sp.second << endl;

    return 0;
}

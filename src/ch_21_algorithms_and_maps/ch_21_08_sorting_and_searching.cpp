#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct No_case {
    bool operator()(const string& x, const string& y) const
    {
        for (size_t i = 0; i < x.length(); i++)
        {
            if (i == y.length())
                return false; // y < x

            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx < yy)
                return true; // x < y
            if (yy < xx)
                return false; // < x

        }

        return true; // x < y (fewer characters in x)
    }
};

struct Fruit {
    string name;
    Fruit(const char *n)
        : name{n}
    {  }
};

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name < b.name;
    }
};

int main()
{
    vector<Fruit> vs;
    vs.push_back(Fruit("Apple"));
    vs.push_back(Fruit("Banana"));
    vs.push_back(Fruit("Watermelon"));
    vs.push_back(Fruit("Starfruit"));
    vs.push_back(Fruit("Lemon"));
    vs.push_back(Fruit("Lime"));
    vs.push_back(Fruit("Orange"));
    vs.push_back(Fruit("Pear"));
    vs.push_back(Fruit("Strawberry"));
    vs.push_back(Fruit("Grape"));
    vs.push_back(Fruit("Pear"));

    sort(vs.begin(), vs.end(),
            [](const Fruit& a, const Fruit& b){ return a.name < b.name; });

    for (auto it : vs)
        cout << it.name << endl;
    cout << endl;

    typedef vector<Fruit>::iterator FI;
    pair<FI, FI> ff = equal_range(vs.begin(), vs.end(), "Pear",
            [](const Fruit& a, const Fruit& b){ return a.name < b.name; });

    for (FI p = ff.first; p != ff.second; ++p)
        cout << p->name << endl;
}

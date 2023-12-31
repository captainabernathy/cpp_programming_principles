// program demonstrates the use of function return values

#include <vector> // for vector
#include <string> // for string
#include <iostream> // for cout

// function declaration
double fct(int a, double d);

// function definition... fct returns product of its inputs
double fct(int a, double d)
{
    return a * d;
}

// more function declarations
int current_power();
void increase_power(int level);

// same function declared twice...
// NOTE: You can declare... but NOT define... the same function twice in a
// single translation unit
int my_find(std::vector<std::string> vs, std::string s, size_t hint);
int my_find(std::vector<std::string>, std::string, size_t);

// function searches for s in vs and uses hint as a potential starting index
// function returns index of s in vs if found or -1 if not
int my_find(std::vector<std::string> vs, std::string s, size_t hint)
{
    // set hint to zero if it isn't within the bounds of vs
    if (vs.size() <= hint)
        hint = 0;

    // search for s in vs from hint
    for (size_t i = hint; i < vs.size(); i++)
        if (vs[i] == s)
            return i;

    // search for s in v from start to hint, if not found above
    if (0 < hint)
        for (size_t i = 0; i < hint; i++)
            if (vs[i] == s)
                return i;

    return -1; // not found
}

// NOTE: namespace creates its own scope
namespace different
{
    // definition of my_find() in namespace different
    // function searches for s in vs and hint is omitted bc it is not used
    // function returns index of s in vs if found or -1 if not
    int my_find(std::vector<std::string> vs, std::string s, size_t)
    {
        // search for s in v
        for (size_t i = 0; i < vs.size(); i++)
            if (vs[i] == s)
                return i;
        return -1; // not found
    }
}

int main()
{
    using std::cout;
    using std::vector;
    using std::string;

    cout << fct(1, 3.7) << "\n\n";

    const int N = 4;
    
    // array of c strings
    const char *cities[N] = {"Aarhus", "Brussels", "Cincinatti", "Dublin"};

    // initialize vector using iterators/pointers to first and last elements
    // in cities
    vector<string> v(cities, cities + N);

    cout << "N = " << N << '\n'; // 4

    // write cities to stdout
    for (auto it : cities)
        cout << it << '\n';
    cout << '\n';

    // search for Dublin in v using my_find()
    cout << my_find(v, "Dublin", 2) << '\n'; // 3

    // search for Dublin in v using different::my_find()
    cout << different::my_find(v, "Dublin", 2) << '\n'; // 3

    return 0;
}

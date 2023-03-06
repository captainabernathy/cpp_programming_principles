// program demonstrates vector declaration, initialization, and iteration
// techniques

#include <iostream> // I/O library header
#include <string> // string library header
#include <vector> // vector library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    // construct vector with storage for 6 integer elements
    vector<int> v(6);
    // initialize each element individually
    v[0] = 5;
    v[1] = 7;
    v[2] = 9;
    v[3] = 4;
    v[4] = 6;
    v[5] = 8;

    // for-each vector traversal...

    // for each int i in v...
    for (int i : v)
        cout << i << endl; // write value to stdout
    cout << endl;

    // a variable declared as auto can be used to iterate over a vector without
    // explicitly declaring its type... bc the compiler automatically deduces
    // its type based on the type of iterator associated with the object
    
    // auto for-each loop with ints
    for (auto i : v)
        cout << i << endl; // write value to stdout
    cout << endl;

    // construct a vector with storage for 4 string elements
    vector<string> philosopher(4);
    // initialize each element individually
    philosopher[0] = "Kant";
    philosopher[1] = "Plato";
    philosopher[2] = "Hume";
    philosopher[3] = "Kierkegaard";
   
    // for each string i in philosopher
    for (string i : philosopher)
        cout << i << endl; // write value to stdout
    cout << endl;

    // auto for-each loop with strings
    for (auto i : philosopher)
        cout << i << endl; // write result to stdout
    cout << endl;

    // construct a vector with storage for 1000 doubles, each initialized to
    // the value of -1.2
    vector<double> vd(1000, -1.2);

    // auto for-each loop with doubles
    for (auto i : vd)
        cout << i << endl; // write value to stdout
    cout << endl;

    return 0;
}

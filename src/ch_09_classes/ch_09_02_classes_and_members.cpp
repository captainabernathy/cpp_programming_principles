// program implements a simple class and demonstrates usage of objects created
// from it

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// user-defined type
class X {
public:
    // public attribute
    int m;

    // public function
    int mf(int v)
    {
        int old = m;
        m = v;
        return old;
    }
};

int main()
{
    X var; // construct an instance of X
    // use the dot '.' operator to access member functions and variables
    var.m = 7; // assignment to an object's public attribute
    cout << var.m << endl; // 7
    int x = var.mf(9); // call to an object's public member function
    cout << x << endl; // 7
    cout << var.m << endl; // 9
    return 0;
}

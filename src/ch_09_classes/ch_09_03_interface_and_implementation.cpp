// program demonstrates the implementation and usage of a class that contains
// public and private attributes and functions

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// user-defined type
class X {
    // private attribute
    int m;

    // private member function
    int mf() { return m; }

public:

    // public member function
    int f(int i)
    {
        m = i; // update private attribute
        return mf(); // call private function
    }
};

int main()
{
    X x; // construct an instance of x
    int y = x.f(2); // call x's public function
    cout << y << endl; // 2
    return 0;
}

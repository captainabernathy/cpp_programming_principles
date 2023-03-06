// program demonstrates the use of constexpr and const (read-only) variables

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    // constexpr variables must be know at compile-time
    constexpr double pi = 3.14159265359; // a literal is a constant expression
    cout << pi << endl; // 3.14..

    // constexpr variables my be initialized using other constexpr variables
    constexpr double two_pi = pi * 2;
    cout << two_pi << endl; // 6.28...

    // normal variables can be initialized using const or constexpr variables
    double p = pi; // p is a normal variable whose value can be changed
    cout << p << endl; // 3.14...

    p = 2 * pi; // update p
    cout << p << endl; // 6.28...

    // constexpr variables cannot be initialized using variables not declared
    // using constexpr
    // constexpr double d = p; // error

    int r = 7;
    cout << r << endl; // 7

    int v = 2 * pi / r; // reading from pi... v is truncated
    cout << v << endl; // 0

    // const variables may be initialized from normal variables and variables 
    // whose values are not know at compile time 
    const int max = r + 12;
    cout << max << endl; // 19

    int val = 19;
    cout << val << endl; // 19

    cout << max + 2 << endl; // 21
    cout << val + 2 << endl; // 21

    // const and constexpr variables are considered read-only variables, so
    // neither may be updated following initialization
    // max = r; // error
    // pi = two_pi / 2; // error

    return 0;
}

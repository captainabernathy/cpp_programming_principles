// program demonstrates various integral type conversions that do not result
// in the loss of precision

#include <iostream> // I/O library header
#include "std_lib_facilities.h" // project header containing helper functions
using namespace std; // add names from std namespace to global namespace

int main()
{
    char c = 'x';
    int i1 = c; // char promoted to int... safe conversion
    int i2 = 'x'; // ok bc sizeof(int) guaranteed to be >= sizeof(char)

    // not the best idea bc conversion from int to char is
    // implementation defined
    char c2 = i1;

    cout << c << ' '    // x
        << i1 << ' '    // 120
        << c2 << ' '    // x
        << i2 << endl;  // 120

    double d1 = 2.3;
    double d2 = d1 + 2;

    if (d1 < 0)
        error("d1 is negative"); // project defined error function

    cout << d1 << ' '  // 2.3
        << d2 << endl; // 4.3

    return 0;
}

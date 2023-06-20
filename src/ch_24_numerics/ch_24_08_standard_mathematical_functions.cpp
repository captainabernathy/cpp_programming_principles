// program demonstrates how to use some of the standard library's mathematical
// functions

#include <cerrno> // for errno, EDOM
#include <cmath> // for sqrt(), pow()
#include <limits> // for numeric_lmits<>
#include <iostream> // for cerr

int main()
{
    using std::cerr;

    // always set errno to 0 prior to calling a function that might set it
    errno = 0;
    double s1 = sqrt(-1.0); // sqrt() might set errno

    if (errno)
        cerr << "something went wrong\n\n";
    if (errno == EDOM)
        cerr << "sqrt() not defined for negative argument\n\n";

    const double very_large = std::numeric_limits<double>::max();

    errno = 0;
    pow(very_large, 4); // pow() might set errno

    if (errno == ERANGE)
        cerr << "pow (" << very_large << ", 4) too large for a double\n";

    return 0;
}

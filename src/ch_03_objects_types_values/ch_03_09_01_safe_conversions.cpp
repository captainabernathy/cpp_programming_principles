// program demonstrates various integral type conversions that do not result
// in the loss of precision

#include <iostream> // for cout
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::cout;

    char c = 'x';
    int i1 = c; // char promoted to int... safe conversion
    int i2 = 'x'; // ok bc sizeof(int) guaranteed to be >= sizeof(char)

    // not the best idea bc conversion from int to char is
    // implementation defined
    char c2 = i1;

    cout << c << ' '    // x
        << i1 << ' '    // 120
        << c2 << ' '    // x
        << i2 << '\n';  // 120

    double d1 = 2.3;
    double d2 = d1 + 2;

    if (d1 < 0)
        error("d1 is negative"); // project defined error function

    cout << d1 << ' '  // 2.3
        << d2 << '\n'; // 4.3

    return 0;
}

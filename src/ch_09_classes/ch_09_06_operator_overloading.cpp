// program demonstrates how to overload various operators and tests the
// implementations of an overloaded pre-increment operator and output operator
// for the Month enum
//
// Month (enum)
// Month operator++(Month& m)
// ostream& operator<<(ostream& os, Month m)

#include <iostream> // for cout, ostream
#include <chrono_utils/month_utils.hpp> // for Month

// empty user defined type
class Vector {};

// NOTE: you can't overload built-in operators for standard types
// int operator+(int, int);

// declaration of overloaded addtion operator for 2 vectors
Vector operator+(const Vector&, const Vector&);

// declaration of overloaded += operator for vector and a scalar
Vector operator+=(const Vector&, int);

int main()
{
    using std::cout;

    // initialize a Month and test pre-incrementation operator
    Month m = sep;
    cout << m << '\n'; // September
    cout << ++m << '\n'; // October
    cout << ++m << '\n'; // November
    cout << ++m << '\n'; // December
    ++m;
    cout << m << '\n'; // wraps to... January

    return 0;
}

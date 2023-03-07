// program demonstrates how to overload operators

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// enum defining symbolic constants for months
enum Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

// prefix increment operator overload for Month
Month operator++(Month& m)
{
    m = (m == dcm) ? jan : Month(m + 1);
    return m;
}

// overloaded output operator for Month
ostream& operator<<(ostream& os, Month m)
{
    // lookup month lookup table
    static const char *month_tbl[12] = { "January", "February", "March",
        "April", "May", "June", "July", "August", "September", "October",
        "November", "December"
    };

    return os << month_tbl[m - 1];
}

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
    // initialize a Month and test pre-incrementation operator
    Month m = sep;
    cout << m << endl; // September
    cout << ++m << endl; // October
    cout << ++m << endl; // November
    cout << ++m << endl; // December
    ++m;
    cout << m << endl; // wraps to... January
    return 0;
}

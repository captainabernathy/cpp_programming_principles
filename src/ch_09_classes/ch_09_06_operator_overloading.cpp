// program demonstrates how to overload operators

#include <iostream> // I/O library header

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
std::ostream& operator<<(std::ostream& os, Month m)
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

// program implements a class for representing dates as well as an overloaded
// output operator for writing dates to an output stream

#include <iostream> // I/O library header

// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // default constructor
    Date() {  }

    // constructor... initializes a Date's private data members from input
    Date(int yy, Month mm, int dd)
        : y {yy}, m {mm}, d {dd} {  }

    // return a Date's month
    Month month() const { return m; }

    // return a Date's day
    int day() const { return d; }

    // return a Date's year
    int year() const { return y; }

private:
    // private attributes
    int y;
    Month m;
    int d;
};

// overloaded output operator for Dates
// writes and formats Date d to output steream os
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << "(" << d.year() << "," << d.month() << "," << d.day() << ")";
}

int main()
{
    using std::cout;

    // create some new Dates
    Date d1 {1994, Date::mar, 29};
    Date d2 {2000, Date::feb, 15};

    // output Dates
    cout << d1 << '\n';
    cout << d2 << '\n';

    operator<<(cout, d1); // call output operator directly
    cout << '\n';

    cout << d1 << d2 << '\n';

    operator<<(operator<<(cout, d1), d2); // call output operator directly
    cout << '\n';

    return 0;
}

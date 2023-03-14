// program implements a class for representing dates as well as an overloaded
// output operator for writing dates to an output stream

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // default constructor
    Date(){  }

    // constructor... initializes a Date's private data members from input
    Date(int yy, Month mm, int dd)
        : y(yy), m(mm), d(dd){  }

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
ostream& operator<<(ostream& os, const Date& d)
{
    return os << "(" << d.year() << "," << d.month() << "," << d.day() << ")";
}

int main()
{
    // create some new Dates
    Date d1(1994, Date::mar, 29);
    Date d2(2000, Date::feb, 15);

    // output Dates
    cout << d1 << endl;
    cout << d2 << endl;

    operator<<(cout, d1); // call output operator directly
    cout << endl;

    cout << d1 << d2 << endl;

    operator<<(operator<<(cout, d1), d2); // call output operator directly
    cout << endl;

    return 0;
}

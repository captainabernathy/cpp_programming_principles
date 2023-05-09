// program illustrates the implementation of a class with a friend method that
// is able to access private members

#include <iostream> // I/O library header

// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // public member functions
    // constructor... initializes a Date's private data members from input
    Date(int yy, Month mm, int dd)
        : y {yy}, m {mm}, d {dd} {  }

    // friend declaration grants operator<< access to private members
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    // {
        // return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
    // }

private:
    // private attributes
    int y;
    Month m;
    int d;
};

int main()
{
    using std::cout;

    Date holiday(1978, Date::jul, 4); // build a Date
    cout << holiday << '\n'; // (1978, 7, 4)

    Date d2 = holiday; // initialize new Date via assignment
    cout << d2 << '\n'; // (1978, 7, 4)

    // build a date and assign result to a new Date
    Date d3 = Date(1978, Date::jul, 4);
    cout << d3 << '\n'; // (1978, 7, 4)

    // overwrite holiday with a new Date
    holiday = Date(1978, Date::dec, 24);
    cout << holiday << '\n'; // (1978, 12, 24)

    // overwrite d3 with holiday
    d3 = holiday;
    cout << d3 << '\n'; // (1978, 12, 24)

    cout << Date(1978, Date::dec, 24) << '\n'; // (1978, 12, 24)

    return 0;
}

// overloaded output operator for Date... can access private attributes since
// declared as friend
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}


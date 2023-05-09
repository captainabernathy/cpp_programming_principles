// program demonstrates how to implement a default/no-argument constructor for
// a class

#include <iostream> // I/O library header
#include <vector> // vector library header

// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // public member functions
    // default constructor
    Date();

    // constructor... initializes a Date's private data members from input
    Date(int yy, Month mm, int dd);
   
    // get a Date's month
    Month month() const
    {
        return m;
    }

    // get a Date's day
    int day() const
    {
        return d;
    }

    // get a Date's year
    int year() const
    {
        return y;
    }

private:
    // private attributes
    int y;
    Month m;
    int d;
};

// NOTE: Return a constant reference yields and r-value... an expression that
// can appear on the right side of assignment only... and cannot have a value
// assigned to it
// so... Date d = default_date() is ok, but
// Date d = default_date() = default_date() is not
const Date& default_date()
{
    // NOTE: a static variable is defined only once
    static const Date dd(2001, Date::jan, 1);
    return dd;
}

// default constructor definition
Date::Date()
    : y {default_date().year()},
      m {default_date().month()},
      d {default_date().day()} {  }

// constructor that initializes a date from its input
Date::Date(int yy, Month mm, int dd)
    : y {yy}, m {mm}, d {dd} {  }

int main()
{
    using std::vector;
    using std::cout;

    // construct a 10 element vector of Dates, each initialized using
    // default_date()
    vector<Date> birthdays(10, default_date());

    // change one of the Dates in birthdays
    birthdays[0] = Date(1999, Date::dec, 31);
   
    // write birthdays to stdout
    for (auto it : birthdays)
        cout << it.month() << ' ' << it.day() << ' ' << it.year() << '\n';
    cout << '\n';

    return 0;
}

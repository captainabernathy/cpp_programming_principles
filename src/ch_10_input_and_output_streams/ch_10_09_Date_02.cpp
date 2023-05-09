// program implements a class for representing dates as well as overloaded
// input and output operators for reading and writing dates to and from
// input and output streams

#include <iostream> // I/O library header

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

    // return a Date's day
    Month month() const
    {
        return m;
    }

    // return a Date's month
    int day() const
    {
        return d;
    }

    // return a Date's year
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

// overloaded input operator for Dates
// reads Date dd into input stream is
// NOTE: Date dd should be formatted as "(year,month,day)"
std::istream& operator>>(std::istream& is, Date& dd);

// overloaded output operator for Dates
// writes and formats Date d to output steream os
std::ostream& operator<<(std::ostream& os, const Date& d);

int main()
{
    using std::cout;
    using std::cin;
  
    // read a date from stdin and write it to stdout
    Date d;
    cout << "Enter date: ";
    cin >> d;

    cout << '\n';

    cout << "d is " << d << '\n';

    return 0;
}

std::istream& operator>>(std::istream& is, Date& dd)
{
    int y;
    int m;
    int d;
    char ch1;
    char ch2;
    char ch3;
    char ch4;

    // read date as (year,month,day)
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

    // return input stream if it is not good
    if (!is)
        return is;

    // test date formatting
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
    {
        // set stream error state to failed... format error
        is.clear(std::ios_base::failbit);
        return is;
    }

    dd = Date {y, Date::Month(m), d}; // update dd
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year() << "," << d.month() << "," << d.day() << ")";
}

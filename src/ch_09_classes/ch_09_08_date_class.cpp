// program implements a class for representing dates

#include <ios> // for boolalpha
#include <iostream> // for cout, cerr, ostream

// namespace for Date-related stuff
namespace Chrono {
// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // embedded class for throwing
    class Invalid {  };

    // constructor... initializes a Date's private data members from input
    Date(int y, Month m, int d);
    
    // default constructor
    Date();

    // return a Date's day
    int day() const { return d; }

    // return a Date's month
    Month month() const { return m; }

    // return a Date's year
    int year() const { return y; }

    void add_year(int n);

private:
    // private attributes
    int y;
    Month m;
    int d;
};

// namespace function declarations
bool is_date(int y, Date::Month m, int d);
bool leapyear(int y);
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& dd);
}

// continuing namespace
namespace Chrono {

// constructor that initializes a date from its input
Date::Date(int yy, Month mm, int dd)
    : y {yy}, m {mm}, d {dd}
{
    if (!is_date(yy, mm, dd))
        throw Invalid();
}

// returns a default date
inline const Date& default_date()
{
    // NOTE: static variables created within functions are initializes once
    static const Date dd(2001, Date::jan, 1);
    return dd;
}

// default constructor
Date::Date()
    : y {default_date().year()},
      m {default_date().month()},
      d {default_date().day()} {  }


// function updates a Date's year by n
void Date::add_year(int n)
{
    if (m == feb && d == 29 && !leapyear(y + n))
    {
        m = mar;
        d = 1;
    }

    y += n;
}

// function validates if its input represents a date
bool is_date(int y, Date::Month m, int d)
{
    if (d <= 0) // day must be > 0
        return false;

    int days_in_month; // max days in a month

    // update days_in_month for months that do not have 31 days
    switch (m)
    {
        case Date::feb:
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;
        case Date::apr: case Date::jun: case Date::sep: case Date::nov:
            days_in_month = 30;
            break;
        default:
            days_in_month = 31;
    }

    if (days_in_month < d) // day cannot exceed days_in_month
        return false;

    return true;
}

// determines if year received as input is a leapyear
// NOTE: dummy implementation
bool leapyear(int y) { return false; }

// overloaded equality operator for Dates
// two dates are the same only if each of their attributes are the same
inline bool operator==(const Date& a, const Date& b)
{
    return a.year() == b.year() && a.month() == b.month()
        && a.day() == b.day();
}

// overloaded inequality operator for Dates
inline bool operator!=(const Date& a, const Date& b)
{
    return !(a == b); // negates call to overloaded equality operator
}

// overloaded output operator for Dates
// writes and formats Date d to output steream os
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day()
        << ')';
}

// overloaded input operator for Dates
// reads Date dd into input stream is
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

    dd = Date(y, Date::Month(m), d); // update dd

    return is;
}

enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

// more helper functions
// NOTE: dummy implementation
inline Day day_of_week(const Date& d)
{
    return sunday;
}

// NOTE: dummy implementation
inline Date next_sunday(const Date& d)
{
    return d;
}

// NOTE: dummy implementation
inline Date next_weekday(const Date& d)
{
    return d;
}
}

int main()
{
    using std::cerr;

    try
    {
        using std::cout;

        // build a Date
        Chrono::Date holiday(1978, Chrono::Date::jul, 4);
        cout << holiday << '\n';

        // initialize Date via function call
        Chrono::Date d2 = Chrono::next_sunday(holiday);
        cout << d2 << '\n';

        // initialize Date via function call
        Chrono::Day d = day_of_week(d2);
        cout << d << '\n'; // 0

        // output Dates
        cout << "holiday is " << holiday << " d2 is " << d2 << '\n';
        
        cout << std::boolalpha;

        // test Date inequality operator
        cout << (holiday != d2) << '\n'; // 0... false
    }
    catch (Chrono::Date::Invalid&)
    {
        cerr << "error: Invalid date\n";
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

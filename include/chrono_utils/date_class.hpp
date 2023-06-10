#ifndef DATE_CLASS_HPP
#define DATE_CLASS_HPP

#include <ostream> // for ostream
#include <istream> // for istream

// only defined when Dates support the Year class
#ifdef HAS_YEAR
#include <chrono_utils/year.hpp>
#endif

// disables support for the Chrono namespace when defined
#ifndef NO_CHRONO_NS
namespace Chrono {
#endif

// user-defined Date type
class Date {
public:
// only defined when Dates don't support Months
#ifndef NO_MONTH
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
#endif

// not defined when Dates support error handling
#ifndef NO_INVALID
    // embedded class for throwing
    class Invalid { };
#endif

// not defined when Dates are default constructible
#ifndef NO_DEFAULT_CONS
    // default constructor
    Date();
#endif

// only defined when Dates support the Year class
#ifdef HAS_YEAR_CONS
    // constructor... initializes a Date's private data members from input
    Date(Year y, Month m, int d);
// disables support for the Month constructor when defined
#elif !defined NO_MONTH_CONS
    Date(int y, Month m, int d);
#else
    Date(int y, int m, int d);
#endif

// disables support for the day() method when defined
#ifndef NO_DAY_METH
    // return a Date's day
    int day() const
    {
        return dy;
    }
#endif

// disables support for the month() method when defined
#ifndef NO_MONTH_METH
    // return a Date's month
// only defined when Dates don't support Months
#ifndef NO_MONTH
    Month month() const
#else
    int month() const
#endif
    {
        return mo;
    }
#endif

// disables support for the year() method when defined
#ifndef NO_YEAR_METH
    // return a Date's year
    int year() const
    {
        return yr;
    }
#endif

// disables support for the add_year() method when defined
#ifndef NO_ADD_YEAR_METH
    void add_year(int n);
#endif

// only defined when outputting a Date requires accessing private members
#ifdef HAS_FRIEND_DATE_OUTPUT_OP
    friend std::ostream& operator<<(std::ostream& os, Date const& d);
#endif

private:
    // private attributes
// only defined when Dates support the Year class
#ifdef HAS_YEAR
    Year yr;
#else
    int yr;
#endif

// only defined when Dates don't support Months
#ifndef NO_MONTH
    Month mo;
#else
    int mo;
#endif

    int dy;

// only defined when the check() method is used to handle errors
#ifdef HAS_CHECK_METH
    // private member functions
    // returns true when mo is between 1 and 12 inclusive... false otherwise
    bool check();
#endif

};

// disables support for the default_date() function when defined
#ifndef NO_DEFAULT_FN
Date const& default_date();
#endif

// disables support for the is_date() function when defined
#ifndef NO_IS_DATE_FN
// function returns true when a valid Date can be constructed from y, m,
// and d... false otherwise
bool is_date(int y, Date::Month m, int d);
#endif

// disables support for the leapyear() function when defined
#ifndef NO_LEAP_YEAR_FN
// determines if the year y is a leapyear
bool leapyear(int y);
#endif

// disables support for the equality operator for Dates when defined
#ifndef NO_DATE_EQ_OP
bool operator==(Date const& a, Date const& b);
#endif

// disables support for the inequality operator for Dates when defined
#ifndef NO_DATE_INEQ_OP
bool operator!=(Date const& a, Date const& b);
#endif

// disables output operations on Dates when defined
#ifndef NO_DATE_OUTPUT_OP
// overloaded output operator for Dates
// writes and formats Date d to output steream os
std::ostream& operator<<(std::ostream& os, Date const& d);
#endif

// disables input operations on Dates when defined
#ifndef NO_DATE_INPUT_OP
// overloaded input operator for Dates
// reads Date dd into input stream is
// NOTE: Date dd should be formatted as "(year,month,day)"
std::istream& operator>>(std::istream& is, Date& d);
#endif

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
}
#endif

#endif

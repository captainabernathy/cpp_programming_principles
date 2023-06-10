#include <chrono_utils/date_class.hpp>

// only defined when Dates support the Year class
#ifdef HAS_YEAR
#include <chrono_utils/year.hpp> // for Year
#endif

// disables support for the Chrono namespace when defined
#ifndef NO_CHRONO_NS
// continuing namespace
namespace Chrono {
#endif

// disables support for the leapyear() function when defined
#ifndef NO_LEAP_YEAR_FN
// determines if the year y is a leapyear
// NOTE: dummy implementation
bool leapyear(int y)
{
    return false;
}
#endif

// disables support for the is_date() function when defined
#ifndef NO_IS_DATE_FN
// function returns true when a valid Date can be constructed from y, m,
// and d... false otherwise
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
#endif

// only defined when the check() method is used to handle errors
#ifdef HAS_CHECK_METH
// returns true if month is between 1 and 12 inclusive... false otherwise
bool Date::check()
{
    if (1 > mo || 12 < mo)
        return false;
    return true;
}
#endif

// constructor that initializes a date from its input
// only defined when Dates support the Year class
#ifdef HAS_YEAR_CONS
Date::Date(Year y, Month m, int d)
// disables support for the Month constructor when defined
#elif !defined NO_MONTH_CONS
Date::Date(int y, Month m, int d)
#else
Date::Date(int y, int m, int d)
#endif
    : yr {y}, mo {m}, dy {d}
{
// not defined when Dates support error handling
#ifndef NO_INVALID
// only defined when the check() method is used to handle errors
#ifdef HAS_CHECK_METH
    if (!check())
#else
    if (!is_date(yr, mo, dy))
#endif
        throw Invalid();
#endif
}

// disables support for the default_date() function when defined
#ifndef NO_DEFAULT_FN
// returns a default date
// NOTE: returning a constant reference yields and r-value... an expression
// that can appear on the right side of assignment only... and cannot have a
// value assigned to it
// so... Date d = default_date() is ok, but
// Date d = default_date() = default_date() is not
Date const& default_date()
{
    // NOTE: static variables created within functions are initializes once
    static const Date dd(2001, Date::jan, 1);
    return dd;
}
#endif

// not defined when Dates are default constructible
#ifndef NO_DEFAULT_CONS
// default constructor
Date::Date()
// disables support for the default_date() function when defined
#ifndef NO_DEFAULT_FN
    : yr {default_date().year()},
      mo {default_date().month()},
      dy {default_date().day()}
#endif
{ }
#endif

// disables support for the year() method when defined
#ifndef NO_ADD_YEAR_METH
// function updates a Date's year by n
void Date::add_year(int n)
{
    if (mo == feb && dy == 29 && !leapyear(yr + n))
    {
        mo = mar;
        dy = 1;
    }

    yr += n;
}
#endif

// disables support for the equality operator for Dates when defined
#ifndef NO_DATE_EQ_OP
// overloaded equality operator for Dates
// two dates are the same only if each of their attributes are the same
bool operator==(Date const& a, Date const& b)
{
    return a.year() == b.year() && a.month() == b.month()
        && a.day() == b.day();
}
#endif

// disables support for the inequality operator for Dates when defined
#ifndef NO_DATE_INEQ_OP
// overloaded inequality operator for Dates
bool operator!=(Date const& a, Date const& b)
{
    return !(a == b); // negates call to overloaded equality operator
}
#endif

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
}
#endif

#include <chrono_utils/date_class.hpp>

#include <ostream> // for ostream
#include <istream> // for istream
#include <ios> // for io_base

// disables support for the Chrono namespace when defined
#ifndef NO_CHRONO_NS
// continuing namespace
namespace Chrono {
#endif

#if !defined NO_DATE_OUTPUT_OP \
    || defined HAS_FRIEND_DATE_OUTPUT_OP
// overloaded output operator for Dates
// writes and formats Date d to output steream os
std::ostream& operator<<(std::ostream& os, Date const& d)
{
// only defined when outputting a Date requires accessing private members
#ifdef HAS_FRIEND_DATE_OUTPUT_OP
    return os << '(' << d.yr << ',' << d.mo << ',' << d.dy << ')';
#else
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
#endif
}
#endif

// disables input operations on Dates when defined
#ifndef NO_DATE_INPUT_OP
// overloaded input operator for Dates
// reads Date dd into input stream is
std::istream& operator>>(std::istream& is, Date& d)
{
    int y;
    int m;
    int dd;
    char ch1;
    char ch2;
    char ch3;
    char ch4;

    // read date as (year,month,day)
    is >> ch1 >> y >> ch2 >> m >> ch3 >> dd >> ch4;

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

    d = Date(y, Date::Month(m), dd); // update dd

    return is;
}
#endif

// disables support for the Chrono namespace when defined
#ifndef NO_CHRONO_NS
}
#endif

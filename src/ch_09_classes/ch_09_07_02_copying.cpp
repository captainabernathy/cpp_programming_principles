// program tests the implementation of the Date class, which now includes
// an output operator that is a friend of class since it accesses a Date's
// private attributes
//
// Date (class)
//      Month (enum)
//      Date(int y, Month m, int d)
//      friend ostream& operator<<(ostream& os, Date const& d)

#include <iostream> // for cout, ostream

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date

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

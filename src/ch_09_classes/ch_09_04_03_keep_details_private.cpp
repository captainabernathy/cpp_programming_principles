// program tests the implementation of the Date class, which represents a date
// as a year, month, and day
//
// Date (class)
//      Date(int y, int m, int d)
//      int month() const
//      int year() const
//      int day() const

#include <iostream> // for cout

// make expanded Date features hidden from syntax checkers
#if !defined NO_CHRONO_NS \
    && !defined NO_MONTH \
    && !defined NO_MONTH_CONS \
    && !defined NO_IS_DATE_FN
#define NO_CHRONO_NS
#define NO_MONTH
#define NO_MONTH_CONS
#define NO_IS_DATE_FN
#endif

#include <chrono_utils/date_utils.hpp> // for Date

int main()
{
    using std::cout;

    Date birthday(1970, 12, 30); // construct a date

    // call birthday's public functions...
    cout << birthday.month() << '\n'; // 12
    cout << birthday.year() << '\n'; // 1970
    cout << birthday.day() << '\n'; // 30

    return 0;
}

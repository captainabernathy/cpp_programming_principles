// program tests the implementation of the Date class, which now includes a
// default/no-argument constructor
//
// Date (class)
//      Month (enum)
//      Date()
//      Date(int y, Month m, int d)
//      Month month() const
//      int day() const
//      int year() const
//
// Date const& default_date()

#include <iostream> // for cout
#include <vector> // for vector

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date

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

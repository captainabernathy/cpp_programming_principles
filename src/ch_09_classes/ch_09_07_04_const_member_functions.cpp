// program tests the implementation of the Date class, which now includes
// constant member functions
//
// Date (class)
//      Month (enum)
//      Date(int y, Month m, int d)
//      int day() const

#include <iostream> // for cout

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date

int main()
{
    Date d(2000, Date::jan, 20); // build a date
    const Date cd(2001, Date::feb, 21); // cd is a read-only Date object

    std::cout << d.day() << " - " << cd.day() << '\n';

    return 0;
}

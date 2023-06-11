// program tests the implementation of an overloaded output operator for Dates
//
// Date (class)
//      Month (enum)
//      Date(int y, Month m, int d)
//
// ostream& operator<<(ostream& os, Date const& d)

#include <iostream> // for cout

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date

int main()
{
    using std::cout;

    // create some new Dates
    Date d1 {1994, Date::mar, 29};
    Date d2 {2000, Date::feb, 15};

    // output Dates
    cout << d1 << '\n';
    cout << d2 << '\n';

    operator<<(cout, d1); // call output operator directly
    cout << '\n';

    cout << d1 << d2 << '\n';

    operator<<(operator<<(cout, d1), d2); // call output operator directly
    cout << '\n';

    return 0;
}

// program tests the implementation of overloaded input and output operators
// for Dates
//
// Date (class)
//      Month (enum)
//      Date(int y, Month m, int d)
//
// ostream& operator<<(ostream& os, Date const& d)
// istream& operator>>(istream& is, Date& d)

#include <iostream> // for cin, cout

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date

int main()
{
    using std::cout;
    using std::cin;
  
    // read a date from stdin and write it to stdout
    Date d;
    cout << "Enter date (year,month,day): ";
    cin >> d;

    cout << '\n';

    cout << "d is " << d << '\n';

    return 0;
}

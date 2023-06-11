// program tests the implementation of helper functions that can be used for
// working with object created from the Date class
//
// program also implements a local namespace (Chrono) which includes its own
// Date class and helper functions
//
// Date (class)
//      Month (enum)
//      Date(int y, Month m, int d)
//      Month month()
//      int day()
//      int year() const
//
// bool operator!=(Date const& a, Date const& b)
// Date next_sunday(Date const& d)
// Date next_weekday(Date const& d)

#include <ios> // for boolalpha
#include <iostream> // for cout

// make expanded Date features hidden from syntax checkers
#ifndef NO_CHRONO_NS
#define NO_CHRONO_NS
#endif

#include <chrono_utils/date_utils.hpp> // for Date, next_sunday(),
                                       // next_weekday()

// namespace tht redefines Date and helper functions
namespace Chrono {
    class Date { };

    inline Date next_sunday(const Date& d) { return d; }

    inline Date next_weekday(const Date& d) { return d; }

    inline bool leapyear(int d, int m, int y) { return false; }

    inline bool operator==(const Date& a, const Date& b) { return false; }
}

int main()
{
    using std::cout;

    Date d(2008, Date::feb, 23); // construct a Date object
    
    // call Date's member functions
    cout << d.month() << ' ' << d.day() << ' ' << d.year() << '\n';
    
    cout << std::boolalpha;

    // test Date's inequality operator
    cout << (next_sunday(d) != next_weekday(d)) << '\n';

    // test Chrono namespace Date and functions
    Chrono::Date cd1;
    Chrono::Date cd2;
    cout << Chrono::leapyear(5, 6, 7) << '\n';
    using Chrono::operator==;
    cout << (cd1 == cd2) << '\n';

    return 0;
}

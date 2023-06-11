// program tests the implementation of the Chrono namespace, which contains
// the Date class, related features, and helper functions
//
// Chrono (namespace)
//      Date (class)
//          Month (enum)
//          Invalid (class)
//          Date(int y, Month m, int d)
//
//      Day (enum)
//
//      Date next_sunday(Date const& d)
//      Day day_of_week(Date const& d)
//      bool operator!=(Date const&a, Date const& b)
//      ostream& operator<<(ostream& os, Date const& d)

#include <ios> // for boolalpha
#include <iostream> // for cout, cerr, ostream
#include <chrono_utils/date_utils.hpp> // for Date, next_sunday(), day_of_week()

int main()
{
    using std::cerr;

    try
    {
        using std::cout;

        // build a Date
        Chrono::Date holiday(1978, Chrono::Date::jul, 4);
        cout << holiday << '\n';

        // initialize Date via function call
        Chrono::Date d2 = Chrono::next_sunday(holiday);
        cout << d2 << '\n';

        // initialize Date via function call
        Chrono::Day d = day_of_week(d2);
        cout << d << '\n'; // 0

        // output Dates
        cout << "holiday is " << holiday << " d2 is " << d2 << '\n';
        
        cout << std::boolalpha;

        // test Date inequality operator
        cout << (holiday != d2) << '\n'; // 0... false
    }
    catch (Chrono::Date::Invalid&)
    {
        cerr << "error: Invalid date\n";
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

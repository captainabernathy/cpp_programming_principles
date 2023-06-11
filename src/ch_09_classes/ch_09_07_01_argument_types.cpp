// program tests the implementation of the Date class, which now encapsulates
// a Month enum and provides a constructor that supports the Year class
//
// Date (class)
//      Month (enum)
//      Date(Year y, Month m, int d)
//
// Year (class)
//      Year(int y)
//      class Invalid

#include <iostream> // for cerr
#include <chrono_utils/year.hpp> // for Year

// make expanded Date features hidden from syntax checkers
#if !defined NO_CHRONO_NS \
    && !defined HAS_YEAR \
    && !defined NO_YEAR_METH
#define NO_CHRONO_NS
#define HAS_YEAR
#define NO_YEAR_METH
#endif

#include <chrono_utils/date_utils.hpp> // for Date

int main()
{
    using std::cerr;

    try
    {
        // build some Dates
        Date dx3(1998, Date::mar, 30);
        Date dx5(4, Date::mar, 1998); // error
    }
    catch (Year::Invalid&)
    {
        cerr << "error: Invalid year\n";
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

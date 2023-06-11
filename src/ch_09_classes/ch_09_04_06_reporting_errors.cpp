// program tests the implementation of the Date class, which now includes a
// nested Invalid class that is thrown when an attempt is made to construct an
// invalid Date
//
// program also tests the implementation of an overloaded output operator for
// Dates
//
// Date (class)
//      Date(int y, int m, int d)
//      Invalid (class)
//
// ostream& operator<<(ostream& os, Date const& d)


#include <iostream> // for cout, cerr, ostream
#include <exception> // for exception

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
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// testing function that builds and prints a Date object
void f(int x, int y)
{
    try
    {
        Date dxy(2004, x, y); // build a Date object
        std::cout << dxy << '\n'; // output Date object
    }
    catch (Date::Invalid &)
    {
        // error("invalid date");
        throw Date::Invalid(); // rethrow exception
    }
}

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        f(1, 29);
        f(12, 29);
        f(15, 29); // error
    }
    catch (Date::Invalid&)
    {
        error("invalid date");
        return 1;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

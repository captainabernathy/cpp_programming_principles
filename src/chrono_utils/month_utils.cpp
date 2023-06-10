#include <chrono_utils/month.hpp> // for Month
#include <ostream> // for ostream
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// returns a Month that corresponds to the int received or calls error
// otherwise...
Month int_to_month(int x)
{
    if (jan > x || dcm < x)
        error("bad month");
    return Month(x);
}

// prefix increment operator overload for Month
Month operator++(Month& m)
{
    m = (m == dcm) ? jan : Month(m + 1);
    return m;
}

// overloaded output operator for Month
std::ostream& operator<<(std::ostream& os, Month m)
{
    // lookup month lookup table
    static const char *month_tbl[12] = { "January", "February", "March",
        "April", "May", "June", "July", "August", "September", "October",
        "November", "December"
    };

    return os << month_tbl[m - 1];
}

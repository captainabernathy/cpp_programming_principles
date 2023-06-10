#ifndef MONTH_UTILS_HPP
#define MONTH_UTILS_HPP

#include <chrono_utils/month.hpp> // for Month
#include <ostream> // for ostream

// returns a Month that corresponds to the int received or calls error
// otherwise...
Month int_to_month(int x);

// prefix increment operator overload for Month
Month operator++(Month& m);

// overloaded output operator for Month
std::ostream& operator<<(std::ostream& os, Month m);

#endif

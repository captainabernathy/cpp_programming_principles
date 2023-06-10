#ifndef DATE_UTILS_HPP
#define DATE_UTILS_HPP

// provides:
// Date (class)
//      Month (enum)
//      Invalid (class)
//      Date()
////////////////////////////////////////
//      Date(Year y, Month m, int d)  //
//      or                            //
//      Date(int y, Month m, int d)   //
//      or                            //
//      Date(int y, int m, int d)     //
////////////////////////////////////////
//      int day() const
////////////////////////////////
//      Month month() const   //
//      or                    //
//      int month() const     //
////////////////////////////////
//      int year() const
//      void add_year(int n)
//
// Date const& default_date()
// bool is_date(int y, Month m, int d)
// bool leapyear(int y)
// bool operator==(Date const& a, Date const& b)
// bool operator!=(Date const& a, Date const& b)
// ostream& operator<<(ostream& os, Date const& d)
// istream& operator>>(istream& is, Date& d)
#include <chrono_utils/date_class.hpp>

// only defined when the day_of_week() function isn't supported
#ifndef NO_DAY
// provides:
// Day (enum)
#include <chrono_utils/day.hpp>
#endif

// disables support for all Day-dependent, Date functions
#ifndef NO_DAY_UTILS
// provides:
// Day day_of_week(Date const& d)
// Date next_sunday(Date const& d)
// Date next_weekday(Date const& d)
#include <chrono_utils/day_utils.hpp>
#endif

#endif

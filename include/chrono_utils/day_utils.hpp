#ifndef DAY_UTILS_HPP
#define DAY_UTILS_HPP

// only defined when the day_of_week() function isn't supported
#ifndef NO_DAY
#include <chrono_utils/day.hpp> // for Day
#endif

#include <chrono_utils/date_class.hpp> // for Date

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
// continuing namespace
namespace Chrono {
#endif

// disables the day_of_week() function when defined
#ifndef NO_DAY_OF_WEEK_FN
Day day_of_week(Date const& d);
#endif

// disables the next_sunday() function when defined
#ifndef NO_NEXT_SUNDAY_FN
Date next_sunday(Date const& d);
#endif

// disables the next_wednesday() function when defined
#ifndef NO_NEXT_WEEKDAY_FN
Date next_weekday(Date const& d);
#endif

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
}
#endif

#endif

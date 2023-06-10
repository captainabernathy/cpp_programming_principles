#ifndef DAY_HPP
#define DAY_HPP

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
// continuing namespace
namespace Chrono {
#endif

enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

// disables the Chrono namespace when defined
#ifndef NO_CHRONO_NS
}
#endif

#endif

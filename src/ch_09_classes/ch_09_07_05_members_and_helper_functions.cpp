// program demonstrates the implementation of helper functions that are used
// for working with object created from a class

#include <iostream> // for cout

// user-defined Date type
class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // constructor... initializes a Date's private data members from input
    Date(int yy, Month mm, int dd)
        : y {yy}, m {mm}, d {dd} {  }

    // return a Date's day
    int day() const { return d; }

    // return a Date's month
    Month month() const { return m; }

    // return a Date's year
    int year() const { return y; }

private:
    // private attributes
    int y;
    Month m;
    int d;
};

// example helper function
inline Date next_sunday(const Date& d) { return d; }

inline Date next_weekday(const Date& d) { return d; }

inline bool leapyear(int d, int m, int y) { return false; }

// overloaded equality operator for Dates
inline bool operator==(const Date& a, const Date& b)
{
    return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
}

inline bool operator!=(const Date& a, const Date& b) { return !(a == b); }

// namespace tht redefines Date and helper functions
namespace Chrono {
    class Date {  };

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
    
    // test Date's inequality operator
    cout << (next_sunday(d) != next_weekday(d)) << '\n';

    return 0;
}

// program demonstrates how to implement a class with constant member functions

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

    // NOTE: const member functions do not modify the object
    int day() const;
    Month month() const;
    int year() const;

private:
    // private attributes
    int y;
    Month m;
    int d;
};

// returns a Date's day
int Date::day() const
{
    return d;
}

int main()
{
    Date d(2000, Date::jan, 20); // build a date
    const Date cd(2001, Date::feb, 21); // cd is a read-only Date object

    std::cout << d.day() << " - " << cd.day() << '\n';

    return 0;
}

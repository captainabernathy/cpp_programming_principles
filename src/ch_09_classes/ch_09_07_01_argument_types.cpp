// program implements a class whose constructor that validates its input

#include <iostream> // for cerr

// user-defined Year type
class Year {
    // private class members
    static const int min = 1800;
    static const int max = 2200;

public:
    // public attributes
    // embedded class for throwing
    class Invalid {};

    // public member functions
    // constructor
    Year(int x)
        : y {x}
    {
        if (x < min || max < x) // input must fall within range of min and max
            throw Invalid();
    }

    // get value of year
    int year() { return y; }

private:
    // private attributes
    int y;
};

// user defined date type
class Date {
public:
    // public attributes
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // public member functions
    // constructor... initializes private data members from input
    Date(Year yy, Month mm, int dd)
        : y {yy}, m {mm}, d {dd} {  }

private:
    // private attributes
    Year y;
    Month m;
    int d;
};

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

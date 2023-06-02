// program implements a Date class that contains a nested class that is used
// for throwing upon the detection of an invalid Date
//
// program also demonstrates how to overload the output operator

#include <iostream> // for cout, cerr, ostream
#include <exception> // for exception

// user-defined date type
class Date {
public:
    // nested class
    class Invalid {  }; // to be used as an exception
   
    // public member functions
    // constructor declaration
    Date(int y, int m, int d);
    
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
    
    void add_day(int n) { /* not implemented */ }

private:
    // private attributes
    int y;
    int m;
    int d;

    // private member functions
    bool check();
};

// constructor definition... uses input to initialize a Date's private
// attributes and validates the result
Date::Date(int yy, int mm, int dd)
    : y {yy}, m {mm}, d {dd}
{
    if (!check()) // throw exception if date invalid
        throw Invalid();
}

// definition of private member function... returns true if month is between
// 1 and 12 inclusive, or false otherwise
bool Date::check()
{
    if (1 > m || 12 < m)
        return false;
    return true;
}

// overloaded definition of an output operator for Date objects (y, m, d)
std::ostream& operator<<(std::ostream& os, Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

// function outputs error message passed to msg
void error(const char *msg)
{
    std::cerr << msg << std::endl;
}

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
        return 0;
    }
    catch (Date::Invalid& )
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

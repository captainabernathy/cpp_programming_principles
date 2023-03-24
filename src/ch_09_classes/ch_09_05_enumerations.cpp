// program demonstrates the use of enums to define symbolic constants

#include <iostream> // I/O library header
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

// enum defining symbolic constants for months
enum Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

// enum defining symbolic constants for days
enum Day {
    monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday
};

// returns a Month that corresponds to the int received or calls error
// otherwise...
Month int_to_month(int x)
{
    if (jan > x || dcm < x)
        error("bad month");
    return Month(x);
}

// function tests int_to_month() function and outputs the result to stdout
void f(int m)
{
    Month mm = int_to_month(m);
    cout << mm << endl;
}

int main()
{
    try
    {
        Month m = feb; // create a Month
        cout << m << endl; // 2
        // m = 7; // cannot assign int to enum type

        int n = m; // Month can be written and converted to int
        cout << n << endl; // 2
        
        // Month bad = 9999; // can't assign int to enum Month
       
        // accessing Enum members
        cout << Month::feb << endl; // 2
        cout << feb << endl; // 2
       
        Month a = m; // can initialize enum type from enum of the same type
        cout << a << endl; // 2
        
        // feb = apr;  // cannot write to enum members
        
        f(4);
        f(99); // runtime error
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}

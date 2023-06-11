// program tests a Month enum that provides symbolic constants that correspond
// to each month (Month::jan => 1, ..., Month::dec=>12)
//
// program also tests the function int_to_month() that returns the enum
// member for the Month that corresponds to a given int
//
// Month (enum)
// Month int_to_month(int x)

#include <iostream> // for cout, cerr
#include <exception> // for exception
#include <chrono_utils/month_utils.hpp> // for Month, int_to_month()
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// function tests int_to_month() function and outputs the result to stdout
void f(int m)
{
    Month mm = int_to_month(m);
    std::cout << mm << '\n';
}

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        Month m = feb; // create a Month
        cout << m << '\n'; // 2
        // m = 7; // cannot assign int to enum type

        int n = m; // Month can be written and converted to int
        cout << n << '\n'; // 2
        
        // Month bad = 9999; // can't assign int to enum Month
       
        // accessing Enum members
        cout << Month::feb << '\n'; // 2
        cout << feb << '\n'; // 2
       
        Month a = m; // can initialize enum type from enum of the same type
        cout << a << '\n'; // 2
        
        // feb = apr;  // cannot write to enum members
        
        f(4);
        f(99); // runtime error
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

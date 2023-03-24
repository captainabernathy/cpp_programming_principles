// program demonstrates the use of a template class to evaluate type conversions
// that may result in loss of data

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <vector> // vector library header
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

int main()
{
    try
    {
        int x = 2.9; // truncated to 2
        cout << x << endl;
    
        char c = 2000; // cannot be represented by a char
        cout << c << endl;

        // NOTE: narrow_cast template provided by std_lib_facilities.h
        // narrow_cast produces a new type of the desired target if its source
        // operand does not change value upon conversion
        int x1 = narrow_cast<int>(2.9); // error due to truncation of 2.9
        cout << x1 << endl;

        int x2 = narrow_cast<int>(2.0); // cast ok
        cout << x2 << endl;

        int c1 = narrow_cast<char>(2000); // error char cannot express 2000
        cout << c1 << endl;

        char c2 = narrow_cast<int>(85); // ok chan can represent 85
        cout << c2 << endl;
    }
    catch (exception &ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!" << endl;
        return 2;
    }

    return 0;
}

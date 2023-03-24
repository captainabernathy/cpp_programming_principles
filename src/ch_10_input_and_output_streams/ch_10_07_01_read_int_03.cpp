// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// program implements rudimentary input validation and also implements the
// function skip_to_int() which enables the input stream to recover upon the
// detection of non-integer input

#include <iostream> // I/O library header
#include <string> // string library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

// utility function for recovering after seeing a bad/unexpected character
void skip_to_int();

int main()
{
    try
    {
        cout << "Please enter an integer in the range of 1 to 10 (inclusive): ";

        int n = 0;
        while (true)
        {
            // read an integer
            if (cin >> n)
            {
                // leave loop if integer is within valid range
                if (1 <= n && n <= 10)
                    break;

                cout << "Sorry " << n << " is not in the [1:10] range. Please "
                    << "try again" << endl;
            }
            else // non-integer was read
            {
                cout << "Sorry, that was not a number. Please try again"
                    << endl;
                skip_to_int(); // call recover function
            }
        }

        cout << n << endl;
        return 0;
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
}

void skip_to_int()
{
    if (cin.fail()) // if we found something that was not an integer
    {
        cin.clear(); // clear stream state so that we can look at it
        char ch;

        while (cin >> ch) // read input
        {
            if (isdigit(ch) || ch == '-')
            {
                // put digit back in input stream so that it can be read again
                cin.unget();
                return;
            }
        }
    }

    error("no input");
}

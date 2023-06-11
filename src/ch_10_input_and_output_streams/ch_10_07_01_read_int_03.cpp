// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// program implements rudimentary input validation and also tests the
// function skip_to_int(), which enables the input stream to recover upon the
// detection of non-integer input
//
// void skip_to_int()

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include "ch_10_utils.hpp" // for skip_to_int()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;
        using std::cin;

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
                    << "try again\n";
            }
            else // non-integer was read
            {
                cout << "Sorry, that was not a number. Please try again\n";
                skip_to_int(); // call recover function
            }
        }

        cout << n << '\n';
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

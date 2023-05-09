// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// program implements the function get_int() that reads an integer from stdin,
// as well as the overloaded version get_int(low,high) that reads an integer
// within the range of low and high from stdin
//
// program also implements the function skip_to_int() which enables the stream
// to recover upon the detection of non-integer input

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <string> // string library header
#include "std_lib_facilities.hpp" // project header containing helper functions

// utility function for recovering after seeing a bad/unexpected character
void skip_to_int();

// function that reads an integer for cin
int get_int();

// function that reads an integer within the range of low and high from cin
int get_int(int low, int high);

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;

        int n = get_int(1, 10);

        cout << "n: " << n << '\n';

        int m = get_int(2, 300);

        cout << "m: " << m << '\n';
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << '\n';
        return 2;
    }

    return 0;
}

int get_int(int low, int high)
{
    std::cout << "Please enter an integer in the range " << low << " to "
        << high << " (inclusive): ";

    while (true)
    {
        int n = get_int(); // read an integer from cin

        if (low <= n && n <= high) // return integer if it is within range
            return n;

        std::cout << "Sorry " << n << " is not in the [" << low << ":" << high
            << "] range. Please try again" << '\n';
    }
}

int get_int()
{
    int n = 0;
    while (true)
    {
        // read an integer and return it, or attempt to recover otherwise
        if (std::cin >> n)
            return n;
        std::cout << "Sorry, that was not a number. Please try again" << '\n';
        skip_to_int(); // recover
    }
}

void skip_to_int()
{
    if (std::cin.fail()) // found something that was not an integer
    {
        std::cin.clear(); // clear stream state so that we can look at it

        char ch;
        while (std::cin >> ch) // read input
        {
            if (isdigit(ch) || ch == '-')
            {
                // put digit back in input stream so that it can be read again
                std::cin.unget();
                return;
            }
        }
    }

    error("no input");
}

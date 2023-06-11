#include "ch_10_utils.hpp"

#include <iostream> // for cin, cout
#include <cctype> // for isdigit()
#include <string> // for string
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// utility function for recovering after seeing a bad/unexpected character
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

// function that reads an integer from cin and returns the result
int get_int()
{
    int n = 0;
    while (true)
    {
        // read an integer and return it, or attempt to recover otherwise
        if (std::cin >> n)
            return n;
        std::cout << "Sorry, that was not a number. Please try again\n";
        skip_to_int(); // recover
    }
}

// function that reads an integer within the range of low and high from cin and
// returns the result
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
            << "] range. Please try again\n";
    }
}

// function that reads an integer with the range of low and high from cin using
// the custom prompt and error messages as prompts to the user and returns
// the result
int get_int(int low, int high, std::string const& prompt,
            std::string const& err_msg)
{
    // prompt user
    std::cout << prompt << ": [" << low << ":" << high << "]\n";

    while (true)
    {
        int n = get_int(); // read an integer from cin

        if (low <= n && n <= high) // return integer if it is within range
            return n;

        std::cout << err_msg << ": [" << low << ":" << high << "]\n";
    }
}

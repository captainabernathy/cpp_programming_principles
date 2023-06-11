// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// program tests the overloaded version of the function get_int()...
// get_int(low,high,promt,err_msg)... that uses the prompt it receives to
// prompt the user to input an integer between low and high and outputs
// err_msg upon the detection of input that is not within the specified range
//
// int get_int(int low, int high, string const& prompt, string const& err_msg)

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include "ch_10_utils.hpp" // for get_int()

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        int strength = get_int(1, 10, "enter strength",
                               "Not in range, try again");

        cout << "strength: " << strength << '\n';

        int altitude = get_int(0, 50000, "please enter altitude in feet",
                               "Not in range, please try again");

        cout << "altitude: " << altitude << " ft above sea level\n";
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

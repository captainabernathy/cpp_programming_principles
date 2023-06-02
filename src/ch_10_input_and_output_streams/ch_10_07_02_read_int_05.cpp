// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// program implements the function get_int() that reads an integer from stdin,
// as well as the overloaded version get_int(low,high,promt,err_msg) that
// uses the prompt it receives to prompt the user to input an integer between
// low and high and outputs err_msg upon the detection of input that is not
// within the specified range
//
// program also implements the function skip_to_int() which enables the stream
// to recover upon the detection of non-integer input

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <cctype> // for isdigit()
#include <string> // for string
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// utility function for recovering after seeing a bad/unexpected character
void skip_to_int();

// function that reads an integer for cin
int get_int();

// function that reads an integer with the range of low and high from cin with
// custom greeting and error messages
int get_int(int low, int high, std::string const& greeting,
            std::string const& sorry);


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

int get_int(int low, int high, std::string const& greeting,
            std::string const& sorry)
{
    // prompt user
    std::cout << greeting << ": [" << low << ":" << high << "]\n";

    while (true)
    {
        int n = get_int(); // read an integer from cin

        if (low <= n && n <= high) // return integer if it is within range
            return n;

        std::cout << sorry << ": [" << low << ":" << high << "]\n";
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

        std::cout << "Sorry, that was not a number... Please try again\n";
        skip_to_int(); // recover
    }
}

void skip_to_int()
{
    if (std::cin.fail()) // found something that wasn't an integer
    {
        std::cin.clear(); // clear stream state so that we can look at it
        
        char ch;
        while (std::cin >> ch) // read input... throw away non-digits
        {
            if (isdigit(ch))
            {
                // put digit back in input stream so that it can be read again
                std::cin.unget();
                return;
            }
        }
    }

    error("no input");
}

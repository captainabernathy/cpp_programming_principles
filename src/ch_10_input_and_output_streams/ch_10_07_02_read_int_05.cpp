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

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <string> // string library header
#include "std_lib_facilities.h" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

// utility function for recovering after seeing a bad/unexpected character
void skip_to_int();

// function that reads an integer for cin
int get_int();

// function that reads an integer with the range of low and high from cin with
// custom greeting and error messages
int get_int(int low, int high, const string& greeting, const string& sorry);


int main()
{
    try
    {
        int strength = get_int(1, 10, "enter strength",
                            "Not in range, try again");
        cout << "strength: " << strength << endl;

        int altitude = get_int(0, 50000, "please enter altitude in feet",
                            "Not in range, please try again");
        cout << "altitude: " << altitude << " ft above sea level" << endl;
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

int get_int(int low, int high, const string& greeting, const string& sorry)
{
    // prompt user
    cout << greeting << ": [" << low << ":" << high << "]" << endl;

    while (true)
    {
        int n = get_int(); // read an integer from cin

        if (low <= n && n <= high) // return integer if it is within range
            return n;

        cout << sorry << ": [" << low << ":" << high << "]" << endl;
    }
}

int get_int()
{
    int n = 0;

    while (true)
    {
        // read an integer and return it, or attempt to recover otherwise
        if (cin >> n)
            return n;

        cout << "Sorry, that was not a number... Please try again" << endl;
        skip_to_int(); // recover
    }
}

void skip_to_int()
{
    if (cin.fail()) // found something that wasn't an integer
    {
        cin.clear(); // clear stream state so that we can look at it
        
        char ch;
        while (cin >> ch) // read input... throw away non-digits
        {
            if (isdigit(ch))
            {
                // put digit back in input stream so that it can be read again
                cin.unget();
                return;
            }
        }
    }

    error("no input");
}

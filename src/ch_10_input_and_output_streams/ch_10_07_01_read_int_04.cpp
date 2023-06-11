// program prompts user for an integer between 1 and 10 (inclusive), reads
// input from stdin, and writes valid input to stdout.
//
// program tests the function get_int() that reads an integer from stdin,
// as well as an overloaded version... get_int(low,high)... that reads an
// integer within the range of low and high from stdin
//
// int get_int()
// int get_int(int low, int high)

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include "ch_10_utils.hpp" // for get_int()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;

        cout << "Enter an integer: ";
        int i = get_int();

        cout << "i: " << i << '\n';

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
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

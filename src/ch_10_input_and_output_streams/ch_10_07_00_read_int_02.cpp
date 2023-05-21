// program prompts user for an integer between 1 and 10 (inclusive), reads input
// from stdin, and writes valid input to stdout.
//
// NOTE: program only performs minimal input validation and fails to detect all
// forms of invalid input

#include <iostream> // for cin, cout

int main()
{
    using std::cout;
    using std::cin;

    cout << "Please enter an integer in the range of 1 to 10 (inclusive): ";

    int n = 0;
    // read an integer within range of 1 and 10 from stdin
    while (cin >> n && !(1 <= n && n <= 10))
        cout << "Sorry " << n << " is not in the [1:10] range." << '\n'
            << "Please try again: ";

    cout << n << '\n';
}

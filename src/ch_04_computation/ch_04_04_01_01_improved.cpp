// program prompts user to enter an integer and a unit and converts inches to
// centimeters or centimeters to inches based on the result
//
// program demonsrates the use of an if/else if/else statement

#include <iostream> // I/O library header

int main()
{
    using std::cout;
    using std::cin;

    constexpr double cm_per_in = 2.54; // constant expression
    int len = 1; // default length
    char unit = ' '; // default  unit

    cout << "Enter a length followed bya a unit (c or i): "; // prompt user
    // read integer and character values into len and unit variables
    cin >> len >> unit;

    // convert from inches to centimeters or centimeter to inches based on
    // given unit
    if (unit == 'i')
        cout << len << "in == " << cm_per_in * len << "cm" << '\n';
    else if (unit == 'c')
        cout << len << "cm == " << len / cm_per_in << "in" << '\n';
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'" << '\n';

    return 0;
}

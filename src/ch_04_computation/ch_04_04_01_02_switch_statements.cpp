// program prompts user to enter an integer and a unit and converts inches to
// centimeters or centimeters to inches based on the result
//
// program demonsrates the use of a switch statement

#include <iostream> // I/O library header

int main()
{
    using std::cout;
    using std::cin;

    constexpr double cm_per_in = 2.54; // constant expression
    int len = 1; // default length
    char unit ='a'; // default unit

    cout << "Enter a length followed by a unit (c or i): "; // prompt user
    // read integer and character values into len and unit variables
    cin >> len >> unit;

    // convert from inches to centimeters or centimeter to inches based on
    // given unit
    // NOTE: the value evaluated in the switch statement must be of an integer,
    // char, or enum type, and the values associated with each case label must
    // be constant expressions
    switch (unit)
    {
        case 'i':
            cout << len << "in == " << cm_per_in * len << "cm" << '\n';
            break;
        case 'c':
            cout << len << "cm == " << len / cm_per_in << "in" << '\n';
            break;
        default:
            cout << "Sorry, I don't know a unit called '" << unit << "'\n";
            break;
    }

    return 0;
}

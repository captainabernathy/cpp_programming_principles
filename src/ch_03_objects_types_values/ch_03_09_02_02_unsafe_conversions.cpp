// program demonstrates the unsafe effect of implicit type conversions by
// prompting the user to enter a double, writing it to an int variable,
// writing the int variable to a char variable, writing the char back to an int,
// and writing the results to stdout

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    // dont do any of this stuff
    double d = 0.;
    
    cout << "Enter a double or CTRL-D to exit:"; // prompt user

    while (cin >> d)
    {
        int i = d; // fractional part truncated in assignment to int
        char c = i; // conversion of int to char is implementatoin defined
        int i2 = c; // char promoted to int, but who knows what's in c?

        cout << "d == " << d << endl
            << "i == " << i << endl
            << "i2 == " << i2 << endl
            << " char (" << c << ")" << endl;

        cout << "Enter a double or CTRL-D to exit:"; // prompt user
    }

    double x = 2.7; // initialize x to 2.7
    cout << x << endl;

    int y = x; // y is initialized to the truncated value of x
    cout << y << endl; // 2

    int a = 1000; // initialize a to 1000
    cout << a << endl;

    // assignment of a to b overflows b... result is implementation defined
    char b = a;
    cout << b << endl; // who knows?

    return 0;
}

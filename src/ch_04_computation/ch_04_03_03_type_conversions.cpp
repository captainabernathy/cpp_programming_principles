// program demonstrates various type conversions that occur when evaluating
// numeric expressions

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    double d = 2.6;
    cout << d << endl; // 2.6

    int i = 2; // 2
    cout << i << endl;

    double d2 = d / i; // i promoted to double for division
    cout << d2 << endl;

    // i promoted to double for division then result truncated for assignment
    int i2 = d / i;
    cout << i2 << endl;

    {
        cout << "Enter a temperature in Celsius: "; // prompt user
        double celsius;
        cin >> celsius;
        // NOTE: 9 / 5 evaluated as integer expression
        double fahrenheit = 9 / 5 * celsius + 32;
        cout << fahrenheit << endl;
    }

    {
        cout << "Enter a temperature in Celsius: "; // prompt user
        double celsius;
        cin >> celsius;
        // NOTE: 9 promoted to double during evaluatoin of 9 / 5.
        double fahrenheit = 9 / 5. * celsius + 32;
        cout << fahrenheit << endl;
    }

    return 0;
}

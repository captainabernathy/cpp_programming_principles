// program demonstrates various type conversions that occur when evaluating
// numeric expressions

#include <iostream> // for cin, cout

int main()
{
    using std::cout;
    using std::cin;

    double d = 2.6;
    cout << d << '\n'; // 2.6

    int i = 2; // 2
    cout << i << '\n';

    double d2 = d / i; // i promoted to double for division
    cout << d2 << '\n';

    // i promoted to double for division then result truncated for assignment
    int i2 = d / i;
    cout << i2 << '\n';

    {
        cout << "Enter a temperature in Celsius: "; // prompt user
        double celsius;
        cin >> celsius;
        // NOTE: 9 / 5 evaluated as integer expression
        double fahrenheit = 9 / 5 * celsius + 32;
        cout << fahrenheit << '\n';
    }

    {
        cout << "Enter a temperature in Celsius: "; // prompt user
        double celsius;
        cin >> celsius;
        // NOTE: 9 promoted to double during evaluatoin of 9 / 5.
        double fahrenheit = 9 / 5. * celsius + 32;
        cout << fahrenheit << '\n';
    }

    return 0;
}

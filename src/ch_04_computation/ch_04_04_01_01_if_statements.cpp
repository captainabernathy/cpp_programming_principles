// program demonstrates the use of an if/else statement

#include <iostream> // for cin, cout

int main()
{
    using std::cout;
    using std::cin;

    int a = 0;
    int b = 0;
    cout << "Enter two integers: "; // prompt user
    cin >> a >> b; // read integer values into a and b

    // determine which variable's value is larger, and write result to stdout
    if (a < b)
        cout << "max(" << a << ", " << b << ") is " << b << '\n';
    else
        cout << "max(" << a << ", " << b << ") is " << a << '\n';

    return 0;
}

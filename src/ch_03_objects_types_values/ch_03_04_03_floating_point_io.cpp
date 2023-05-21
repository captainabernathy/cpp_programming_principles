// program demonstrates the results of performing arithmetic operations in
// output statements

#include <iostream> // for cin, cout
#include <cmath> // for sqrt()

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter a floating-point value: "; // prompt user
    
    // declare varaible
    double n;
    
    // read double into n
    cin >> n;

    // display results of performing various arithmetic operations on n
    cout << "n == " << n << '\n'
        << "n + 1 == " << n + 1 << '\n' // addition with constant
        << "three times n == " << 3 * n << '\n' // multiplication with constant
        << "twice n == " << n + n << '\n' // addition with variable
        << "n squared == " << n * n << '\n' // multiplication with variable
        << "half of n == " << n / 2 << '\n' // division with constant
        << "square root of n == " << sqrt(n) << '\n'; // function result

    return 0;
}

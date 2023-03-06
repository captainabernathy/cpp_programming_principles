// program prompts user for a double and writes the results of using it in
// various arithmetic expressions to stdout
//
// program demonstrates the results of performing arithmetic operations in
// output statements
#include <iostream> // I/O library header
#include <cmath> // math library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "Enter a floating-point value: "; // prompt user
    
    // declare varaible
    double n;
    
    // read double into n
    cin >> n;

    // display results of performing various arithmetic operations on n
    cout << "n == " << n << endl
        << "n + 1 == " << n + 1 << endl // addition with constant
        << "three times n == " << 3 * n << endl // multiplication with constant
        << "twice n == " << n + n << endl // addition with variable
        << "n squared == " << n * n << endl // multiplication with variable
        << "half of n == " << n / 2 << endl // division with constant
        << "square root of n == " << sqrt(n) << endl; // function result

    return 0;
}

// program demonstrates how to output floating point numbers using the default,
// fixed-point, and scientific notation formats

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    
    cout << 1234.56789 << "\t\t(general)" << endl // 1234.57
         << fixed << 1234.56789 << "\t(fixed)" << endl // 1234.567890
         << scientific << 1234.56789 << "\t(scientific)" // 1.234568e+03
         << endl << endl;

    // defaltfloat chooses b/t scientific and fixed formats to present the user
    // with the most accurate representation of a floating-point value within
    // the precision of the defaultfloat format
    cout << defaultfloat << 1234.56789 << '\t' // 1234.57
         << fixed << 1234.56789 << '\t' // 1234.567890
         << scientific << 1234.56789 << endl; // 1.234568e+03

    cout << 1234.56789 << endl << endl; // 1.24568e+03... formatting sticks

    cout << defaultfloat << 1234.56789 << '\t' // 1234.57
         << fixed << 1234.56789 << '\t' // 1234.567890
         << scientific << 1234.56789 << endl; // 1.234568e+03

    return 0;
}
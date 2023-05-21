// program demonstrates how to specify the precision of floating point output
// for the defalt, fixed, and scientific formats

#include <iostream> // for cout, fixed, scientific, defaultfloat
#include <iomanip> // for setprecision

int main()
{
    using std::cout;
    using std::fixed;
    using std::scientific;
    using std::defaultfloat;
    using std::setprecision;

    cout << 1234.56789 << '\t' // 1234.57
         << fixed << 1234.56789 << '\t' // 1234.567890
         << scientific << 1234.56789 << "\n\n"; // 1.234568e+03

    // for the defaultfloat format setprecision() refers to the total number of
    // digits while for the fixed and scientific formats, setprecision() refers
    // to the number of digits after the decimal point
    cout << defaultfloat << setprecision(5) // set precision to 5 digits
        << 1234.56789 << '\t' // 1234.6... 5 digits total
         << fixed << 1234.56789 << '\t' // 1234.56789... 5 digits after decimal
         << scientific << 1234.56789 // 1.23457e+03... 5 digits after decimal
         << "\n\n";

    cout << defaultfloat << setprecision(8) // set precision to 8 digits
        << 1234.56789 << '\t' // 1234.5679... 8 total digits
         << fixed << 1234.56789 << '\t' // 1234.56789000 8 digits after decimal
         << scientific << 1234.56789  // 1.23456789e+03 8 digits after decimal
         << '\n';

    return 0;
}

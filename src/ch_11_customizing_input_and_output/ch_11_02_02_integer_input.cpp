// program demonstrates how to process integer input in decimal, octal, and
// hexadecimal bases

#include <iostream> // I/O library header

int main()
{
    using std::cout;
    using std::cin;
    using std::hex;
    using std::oct;
    using std::ios;

    int a;
    int b;
    int c;
    int d;

    cout << "Enter a decimal integer, a hexadecimal integer, and two octal "
        << "integers without using prefix notation: ";

    // input: 1234 4d2 2322 2322
    cin >> a >> hex >> b >> oct >> c >> d; // both c and d read octal integers
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n'; // all 1234

    // unset defaults to get >> to accept and correctly interpret 0 and 0x
    // prefixes
    cin.unsetf(ios::dec); // don't assume decimal (so 0x can mean hex)
    cin.unsetf(ios::oct); // don't assume octal (so 12 can mean 12)
    cin.unsetf(ios::hex); // don't assume hex (so 12 can mean 12)

    cout << "Enter a decimal integer, a hexadecimal intger, and two octal "
        << "integers using the prexfix 0x for hexadecimal and 0 for octal: ";

    // input: 1234 0x4d2 02322 02322
    cin >> a >> b >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n'; // all 1234

    return 0;
}

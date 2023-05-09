// program demonstrates how to output integers using decimal, octal, and
// hexadecimal bases

#include <iostream> // I/O library header

int main()
{
    using std::cout;
    using std::hex;
    using std::oct;
    using std::dec;
    using std::showbase;

    // NOTE: integer bases remain in effect until changed
    // decimal output is default for integers
    cout << 1234 << "\t(decimal)" << '\n'  // 1234
        // change to hex output with the hex keyword
         << hex << 1234 << "\t(hexadecimal)" << '\n'  // 4d2
         // change to octal output with the oct keyword
         << oct << 1234 << "\t(octal)" << "\n\n";  //2322

    // then change back to decimal with the dec keyword
    cout << dec << 1234 << '\t' // 1234
        << hex << 1234 << '\t' // 4d2
        << oct << 1234 << '\n'; // 2322
    
    cout << 1234 << "\n\n"; // 2322... octal base is still in effect

    cout << dec << 1234 << '\t' // 1234
        << hex << 1234 << '\t' // 4d2
        << oct << 1234 << '\n'; // 2322
    
    // show base prefixes in subsequent statements... 0x for hex, 0 for oct
    cout << showbase << dec;
    
    cout << dec << 1234 << '\t' // 1234
        << hex << 1234 << '\t' // 0x4d2
        << oct << 1234 << "\n\n"; // 02322

    // all interpreted as decimal
    cout << dec << 1234 << '\t' // 1234
        << 0x4d2 << '\t' // 1234
        << 02322 << '\n'; // 1234

    return 0;
}

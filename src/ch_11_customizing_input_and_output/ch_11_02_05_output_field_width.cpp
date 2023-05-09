// program demonstrates how to manipulate the field width of integer output

#include <iostream> // I/O library header
#include <iomanip> // provides parametric manipulators for streams

int main()
{
    using std::cout;
    using std::setw;

    // setw() sets the field width of the next operation
    // NOTE: text is right justified by default with setw()
    cout << 123456 << '|' // no field width used
        << setw(4) << 123456 << '|' // set width to 4. 123456 exceeds width
        << setw(8) << 123456 << '|' // set width to 8
        << 123456 << '|' << "\n\n"; // field sizes don't stick

    cout << 12345 << '|' // no field width used
        << setw(4) << 12345 << '|' // set width to 4. 123456 exceeds width
        << setw(8) << 12345 << '|' // set width to 8
        << 12345 << '|' << "\n\n"; // field sizes don't stick

    cout << 1234.5 << '|' // no field width used
        << setw(4) << 1234.5 << '|' // set width to 4. 1234.5 exceeds width
        << setw(8) << 1234.5 << '|' // set width to 8
        << 1234.5 << '|' << "\n\n"; // field sizes don't stick

    cout << "asdfg" << '|' // no field width used
        << setw(4) << "asdfg" << '|' // set width to 4. 'asdfg' exceeds width
        << setw(8) << "asdfg" << '|' // set width to 8
        << "asdfg" << '\n'; // field sizes don't stick

    return 0;
}

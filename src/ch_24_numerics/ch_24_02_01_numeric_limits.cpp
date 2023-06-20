// program demonstrates how to find the limit of a numeric type using the
// numeric_limits<> template provided by the <limits> header, as well as using
// the predefined macros provided by the <climits> header

#include <iostream> // for cout
#include <climits> // for INT_MAX
#include <limits> // for numeric_limits<>

int main()
{
    using std::cout;
    using std::numeric_limits;

    cout << "number of bytes in an int: " << sizeof(int) << '\n';
    cout << "largest int: " << INT_MAX << '\n';
    cout << "smallest int: " << numeric_limits<int>::min() << "\n\n";

    // determine if plain chars are signed by default
    if (numeric_limits<char>::is_signed)
        cout << "char is signed\n\n";
    else
        cout << "char is unsigned\n\n";

    // outputs garbage
    cout << "smallest char: " << numeric_limits<char>::min() << '\n';

    cout << "int value of smallest char: " << int(numeric_limits<char>::min())
        << '\n'; // -128

    return 0;
}

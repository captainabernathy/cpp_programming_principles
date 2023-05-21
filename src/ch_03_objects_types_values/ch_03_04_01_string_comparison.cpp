// program demonstrates how the ==, <, and > operators can be used to compare
// strings

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    cout << "Enter two words: "; // prompt user
                                 
    // variable declarations
    string first;
    string second;

    // read strings from stdin into first and second
    cin >> first >> second;

    // == tests strings for equality
    // < tests if one strings comes before another
    // > tests if one string comes after another
    // NOTE: < and > are case sensitive... so "Apple" is less than "apple"
    if (first == second)
        cout << "that's the same word twice" << '\n';
    if (first < second)
        cout << first << " is alphabetically before " << second << '\n';
    if (first > second)
        cout << first << " is alphabetically after " << second << '\n';

    return 0;
}

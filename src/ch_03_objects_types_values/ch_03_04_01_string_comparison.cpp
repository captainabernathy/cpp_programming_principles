// program prompts users for two strings and demonstrates how the ==, <, and >
// operators can be used to compare strings

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
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
        cout << "that's the same word twice" << endl;
    if (first < second)
        cout << first << " is alphabetically before " << second << endl;
    if (first > second)
        cout << first << " is alphabetically after " << second << endl;

    return 0;
}

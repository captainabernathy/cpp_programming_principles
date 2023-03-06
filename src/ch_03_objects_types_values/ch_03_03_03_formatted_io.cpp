// program prompts user for first and last names, reads results into string
// variables, and writes them to stdout
//
// program demonstrates how to read multiple strings with a single input
// statement

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "Enter first and last name: "; // prompt user

    // variable declarations
    string first;
    string last;

    // read two string from stdin into first and last
    cin >> first >> last;

    // write results to stdout
    cout << "Hello, " << first << " " << last << endl;
    return 0;
}

// program prompts user to enter first name and writes results to stdout
//
// program demonstrates basic I/O with cout and cin and the use of a string
// variable

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "First name: "; // prompt user

    // don't declare variables until needed
    string name;

    // NOTE: cin reads up to the the first whitespace character from stdin
    cin >> name; // read a string from stdin into name

    // write results to stdout
    cout << "Hello " << name << "!\n";
    cout << "name" << " is " << name << endl;

    return 0;
}

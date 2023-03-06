// program prompts user for first and last names, reads each into a
// separate string variable, concatenates them and saves the result in another
// string variable, and writes that variable to stdout
//
// program demonstrates the use of the + operator to perform string
// concatenation

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "Enter first and last name: "; // prompt user
    
    // variable declarations
    string first;
    string last;
    
    // read strings into first and last variables
    cin >> first >> last;

    // concatenate first and last into a new string
    string name = first + " " + last;

    // write results to stdout
    cout << "Hello, " << name << endl;

    return 0;
}

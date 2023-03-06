// program prompts user for name and age, reads results into string and integer
// variables, and writes the results to stdout
//
// program initializes variables to default values prior to reading new values
// into them

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "Enter name and age: "; // prompt user

    // initialize variables with default values
    string name = "???";
    int age = -1;

    // read string from stdin into name and int into age
    cin >> name >> age;

    // write results to stdout
    cout << "Hello, " << name << " (age " << age << ")" << endl;
    return 0;
}

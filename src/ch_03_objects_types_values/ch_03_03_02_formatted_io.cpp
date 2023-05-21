// program demonstrates how to initialize variables to default values prior
// to using them in I/O operations

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    cout << "Enter name and age: "; // prompt user

    // initialize variables with default values
    string name = "???";
    int age = -1;

    // read string from stdin into name and int into age
    cin >> name >> age;

    // write results to stdout
    cout << "Hello, " << name << " (age " << age << ")\n";

    return 0;
}

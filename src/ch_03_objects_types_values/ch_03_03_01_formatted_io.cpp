// program demonstrates basic I/O with cin and cout

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    cout << "Enter first name and age: "; // prompt user

    // variable declarations
    string name;
    int age;

    cin >> name; // read string from stdin into name
    cin >> age; // read int from stdin into age

    // write results to stdout
    cout << "Hello, " << name << " (age " << age << ")\n";

    return 0;
}

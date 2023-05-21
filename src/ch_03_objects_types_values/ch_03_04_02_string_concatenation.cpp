// program demonstrates the use of the + operator to perform string
// concatenation

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    cout << "Enter first and last name: "; // prompt user
    
    // variable declarations
    string first;
    string last;
    
    // read strings into first and last variables
    cin >> first >> last;

    // concatenate first and last into a new string
    string name = first + " " + last;

    // write results to stdout
    cout << "Hello, " << name << '\n';

    return 0;
}

// program demonstrates how to read multiple strings with a single input
// statement

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

    // read two string from stdin into the variables first and last
    cin >> first >> last;

    // write results to stdout
    cout << "Hello, " << first << " " << last << '\n';

    return 0;
}

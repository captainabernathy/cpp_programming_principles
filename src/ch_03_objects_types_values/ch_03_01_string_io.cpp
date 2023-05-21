// program demonstrates basic I/O with cin and cout and the use of a string
// variable

#include <iostream> // for cout, cin
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    cout << "First name: "; // prompt user

    // don't declare variables until needed
    string name;

    // NOTE: cin reads up to the the first whitespace character from stdin
    cin >> name; // read a string from stdin into name

    // write results to stdout
    cout << "Hello " << name << "!\n";
    cout << "name" << " is " << name << '\n';

    return 0;
}

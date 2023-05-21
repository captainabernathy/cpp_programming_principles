// program demonstrates how to use a using declaration to bring in names from
// a namespace

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    // using declaration above brings names from std into file's scope
    string name;
    cout << "Please enter your first name: ";
    cin >> name;
    cout << "Hello, " << name << '\n';
    return 0;
}

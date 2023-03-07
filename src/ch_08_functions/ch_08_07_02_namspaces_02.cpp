// program demonstrates how to use a using declaration to bring in names from
// a namespace

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    // using declaration above brings names from std into file's scope
    string name;
    cout << "Please enter your first name: ";
    cin >> name;
    cout << "Hello, " << name << endl;
    return 0;
}

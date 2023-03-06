// program displays the use of the + and - operators in the evaluation of
// binary and unary numerical expressions as well as the use of the + operator
// to perform string concatenation

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int count;
    cout << "Enter an integer: ";
    cin >> count;
    cout << count << endl;

    cout << "Enter first name: ";
    string name;
    cin >> name;
    cout << name << endl;

    // + perfroms addition when evaluating a binary numerical expression
    int c2 = count + 2;
    cout << c2 << endl;

    // + preforms concatenation when used with strings
    string s2 = name + " Jr. ";
    cout << s2 << endl;

    // - performs subtraction when evaluating a binary numerical expressions
    int c3 = count - 2;
    cout << c3 << endl;

    // - preforms negation when evaluating a unary numerical expression
    int age = -100;
    cout << age << endl;

    return 0;
}

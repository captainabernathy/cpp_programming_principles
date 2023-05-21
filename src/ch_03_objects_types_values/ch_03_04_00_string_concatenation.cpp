// program displays the use of the + and - operators in the evaluation of
// binary and unary numerical expressions as well as the use of the + operator
// to perform string concatenation

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    // read an integer from stdin and write it to stdout
    int count;
    cout << "Enter an integer: ";
    cin >> count;
    cout << count << '\n';

    // read a string from stdin and write it to stdout
    cout << "Enter first name: ";
    string name;
    cin >> name;
    cout << name << '\n';

    // + perfroms addition when evaluating a binary numerical expression
    int c2 = count + 2;
    cout << c2 << '\n';

    // + preforms concatenation when used with strings
    string s2 = name + " Jr. ";
    cout << s2 << '\n';

    // - performs subtraction when evaluating a binary numerical expressions
    int c3 = count - 2;
    cout << c3 << '\n';

    // - preforms negation when evaluating a unary numerical expression
    int age = -100;
    cout << age << '\n';

    return 0;
}

// program demonstrates updating a variable via pre-incrementation, compound
// assignment, and a numerical expression

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int a = 0;
    cout << a << endl; // 0
    ++a; // pre-increment operator
    cout << a << endl; // 1
    a += 1; // compound assignment
    cout << a << endl; // 2
    a = a + 1; // addition
    cout << a << endl; // 3

    return 0;
}

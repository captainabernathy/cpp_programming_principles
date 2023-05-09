// program demonstrates updating a variable via pre-incrementation, compound
// assignment, and a numerical expression

#include <iostream> // I/O library header

int main()
{
    using std::cout;

    int a = 0;
    cout << a << '\n'; // 0
    ++a; // pre-increment operator
    cout << a << '\n'; // 1
    a += 1; // compound assignment
    cout << a << '\n'; // 2
    a = a + 1; // addition
    cout << a << '\n'; // 3

    return 0;
}

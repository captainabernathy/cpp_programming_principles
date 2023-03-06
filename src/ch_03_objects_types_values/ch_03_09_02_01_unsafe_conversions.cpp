// program demonstrates the unsafe effect of implicitly converting int to char

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int a = 20000; // initialize a to a large value

    // conversion of int to char is implementation defined
    char c = a; // a overflows b
    int b = c; // not 20000

    if (a != b)
        cout << "oops!: " << a << " != " << b << endl;
    else
        cout << "Wow! We have large characters" << endl;

    return 0;
}

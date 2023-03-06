// program demonstrates the initialization and output of various variable types

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int a = 7;
    int b = 9;
    int c = 'a';
    double x = 1.2;
    string s1 = "Hello, world";
    string s2 = "1.2";

    cout << a << endl  // 7
        << b << endl   // 9
        << c << endl   // 97
        << x << endl   // 1.2
        << s1 << endl  // Hello, world
        << s2 << endl; // 1.2

    return 0;
}

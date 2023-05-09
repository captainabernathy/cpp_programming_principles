// program demonstrates the initialization and output of various variable types

#include <iostream> // I/O library header
#include <string> // string library header

int main()
{
    using std::string;
    using std::cout;

    int a = 7;
    int b = 9;
    int c = 'a';
    double x = 1.2;
    string s1 = "Hello, world";
    string s2 = "1.2";

    cout << a << '\n'  // 7
        << b << '\n'   // 9
        << c << '\n'   // 97
        << x << '\n'   // 1.2
        << s1 << '\n'  // Hello, world
        << s2 << '\n'; // 1.2

    return 0;
}

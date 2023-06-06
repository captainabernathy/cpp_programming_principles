// program demonstrates the initialization and output of various variable types

#include <string> // for string
#include <iostream> // for cout

int main()
{
    using std::string;
    using std::cout;

    int a = 7;
    int b = 9;
    int c = 'a'; // evalutes to numerical value of 'a' in the character set
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

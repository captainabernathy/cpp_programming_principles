// program demonstrates the unsafe effect of implicitly converting int to char

#include <iostream> // for cout

int main()
{
    using std::cout;

    int a = 20000; // initialize a to a large value

    // conversion of int to char is implementation defined
    char c = a; // a overflows b
    int b = c; // not 20000

    if (a != b)
        cout << "oops!: " << a << " != " << b << '\n';
    else
        cout << "Wow! We have large characters\n";

    return 0;
}

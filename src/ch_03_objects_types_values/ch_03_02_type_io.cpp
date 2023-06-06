// program displays how to initialize variables of type int, double, char,
// string, and bool

#include <string> // for string
#include <iostream> // for cout

int main()
{
    using std::cout;
    using std::string;

    int steps = 39; // integer
    double time = 3.5; // double-precision floating-point number
    char dp = '.'; // use single quotes for a single character
    string name = "Bob"; // use double quotes for a string
    bool tap = true; // boolean... true == 1, false == 0

    cout << steps << '\n'   // 39
        << time << '\n'     // 3.5
        << dp << '\n'       // .
        << name << '\n'     // Aaron
        << tap << '\n';     // 1

    return 0;
}

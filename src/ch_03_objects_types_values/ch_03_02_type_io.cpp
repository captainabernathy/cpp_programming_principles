// program displays initialization of variables of type int, double, char,
// string, and bool, and writes results to stdout

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int steps = 39; // integer
    double time = 3.5; // double-precision floating-point number
    char dp = '.'; // use single quotes for a single character
    string name = "Aaron"; // use double quotes for a string
    bool tap = true; // boolean... true == 1, false == 0

    cout << steps << endl   // 39
        << time << endl     // 3.5
        << dp << endl       // .
        << name << endl     // Aaron
        << tap << endl;     // 1

    return 0;
}

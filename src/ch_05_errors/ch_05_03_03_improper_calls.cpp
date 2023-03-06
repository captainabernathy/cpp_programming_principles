// program provides several examples of valid code producing unwanted results
// due to the lack of error checking

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

// simple function that calculates area from its inputs and returns the result
inline int area(int len, int width)
{
    return len * width;
}

int main()
{
    int x4 = area(10, -7); // -7 is valid but doesn't make sense
    cout << x4 << endl; // -70

    int x5 = area(10.7, 9.3); // arguments truncated to 10 and 9
    cout << x5 << endl; // 90

    char x6 = area(100, 9999); // results truncated to char
    cout << x6 << endl; // garbage since value exceeds int

    int x7 = area(4, 4); // valid
    cout << x7 << endl; // 16

    return 0;
}


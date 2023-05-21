// program provides several examples of valid code that produces unwanted
// results due to the lack of error checking

#include <iostream> // for cout

// simple function that calculates area from its inputs and returns the result
inline int area(int len, int width)
{
    return len * width;
}

int main()
{
    using std::cout;

    int x4 = area(10, -7); // -7 is valid but doesn't make sense
    cout << x4 << '\n'; // -70

    int x5 = area(10.7, 9.3); // arguments truncated to 10 and 9
    cout << x5 << '\n'; // 90

    char x6 = area(100, 9999); // results truncated to char
    cout << x6 << '\n'; // garbage since value exceeds int

    int x7 = area(4, 4); // valid
    cout << x7 << '\n'; // 16

    return 0;
}


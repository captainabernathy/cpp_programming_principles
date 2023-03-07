// program illustrates the meaning of passing function arguments by value

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// function increments its input by one and returns the result
inline int f(int x)
{
    x = x + 1;
    return x;
}

int main()
{
    int xx = 0;
    cout << f(xx) << endl; // 1
    cout << xx << endl; // 0.. xx not changed

    int yy = 7;
    cout << f(yy) << endl; // 8
    cout << yy << endl; // 7.. yy not changed

    return 0;
}

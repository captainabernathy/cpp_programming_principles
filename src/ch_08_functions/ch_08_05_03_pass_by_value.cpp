// program illustrates the meaning of passing function arguments by value

#include <iostream> // I/O library header

// function increments its input by one and returns the result
inline int f(int x)
{
    x = x + 1;
    return x;
}

int main()
{
    using std::cout;

    int xx = 0;
    cout << f(xx) << '\n'; // 1
    cout << xx << '\n'; // 0.. xx not changed

    int yy = 7;
    cout << f(yy) << '\n'; // 8
    cout << yy << '\n'; // 7.. yy not changed

    return 0;
}

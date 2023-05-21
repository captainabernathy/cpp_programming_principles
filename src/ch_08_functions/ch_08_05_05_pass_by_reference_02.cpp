// program demonstrates the meaning of passing arguments by reference

#include <iostream> // for cout

// function declarations
int g(int& x);
int f(int& x);

// function receives x by reference, increments, and returns it
// NOTE: x retains update since it was passed by reference
int f(int& x)
{
    x = x + 1;
    return x;
}

int main()
{
    using std::cout;

    int xx = 0;
    cout << f(xx) << '\n'; // 1.. xx updated
    cout << g(xx) << '\n'; // 2.. xx updated
    cout << xx << '\n'; // 2

    int yy = 7;
    cout << f(yy) << '\n'; // 8.. yy updated
    cout << g(yy) << '\n'; // 9.. yy updated
    cout << yy << '\n'; // 9

    return 0;
}

// function receives x by reference, increments, and returns it
// NOTE: x retains update since it was passed by reference
int g(int& x)
{
    x = x + 1;
    return x;
}

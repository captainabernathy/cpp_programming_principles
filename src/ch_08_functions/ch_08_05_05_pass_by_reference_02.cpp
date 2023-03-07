// program demonstrates the meaning of passing arguments by reference

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// function declarations
int g(int& x);
int f(int& x);

// function receives x by receference, increments, and returns it
// NOTE: x retains update since it was passed by reference
int f(int& x)
{
    x = x + 1;
    return x;
}

int main()
{
    int xx = 0;
    cout << f(xx) << endl; // 1.. xx updated
    cout << g(xx) << endl; // 2.. xx updated
    cout << xx << endl; // 2

    int yy = 7;
    cout << f(yy) << endl; // 8.. yy updated
    cout << g(yy) << endl; // 9.. yy updated
    cout << yy << endl; // 9

    return 0;
}

// function receives x by receference, increments, and returns it
// NOTE: x retains update since it was passed by reference
int g(int& x)
{
    x = x + 1;
    return x;
}

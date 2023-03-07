// program demonstrates function implementaion

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int f(int); // function delcaration

// inline function definition
inline int g(int i) { return f(i); }

int main()
{
    cout << g(2) << endl; // 2
    return 0;
}

// f just returns its argument
int f(int n)
{
    return n;
}

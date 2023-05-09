// program demonstrates function implementaion

#include <iostream> // I/O library header

int f(int); // function delcaration

// inline function definition
inline int g(int i) { return f(i); }

int main()
{
    std::cout << g(2) << '\n'; // 2
    return 0;
}

// f just returns its argument
int f(int n)
{
    return n;
}

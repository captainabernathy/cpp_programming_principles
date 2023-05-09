// program demonstrates the use of a for loop to write each even integer from
// 0 to 100 along with its square to stdout

#include <iostream> // I/O library header

// simple function that squares its input and returns the result
inline int square(int x) { return x * x; }

int main()
{
    using std::cout;

    // write each even integer from 0 100 along with its square to stdout
    for (int i = 0; i < 100; i += 2) // increment by two each iteration
        cout << i << '\t' << square(i) << '\n';

    return 0;
}

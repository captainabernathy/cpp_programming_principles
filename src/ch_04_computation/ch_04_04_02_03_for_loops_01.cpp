// program demonstrates the use of a for loop to write each integer from 0 to
// 100 along with its square to stdout

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

// simple function that squares its input and returns the result
inline int square(int x) { return x * x; }

int main()
{
    // write each integer from 0 100 along with its square to stdout
    for (int i = 0; i < 100; i++)
        cout << i << '\t' << square(i) << endl;

    return 0;
}

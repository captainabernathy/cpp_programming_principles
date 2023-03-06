// another program that demonstrates the implementation of a simple inline
// function

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

// simple function that writes the square of its input to stdout
inline void print_square(int v){ cout << v << '\t' << v * v << endl; }

int main()
{
    for (int i = 0; i < 100; i++)
        // function writes each integer and its square to stdout
        print_square(i);

    return 0;
}

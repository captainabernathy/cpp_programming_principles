// program demonstrates the implementation of few simple inline functions

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

// simple function that squares its input and returns the result
inline int square(int x) { return x * x; }

// simple function that writes "Sorry" to stdout
inline void write_sorry() { cout << "Sorry" << endl; }

int main()
{
    cout << square(2) << endl; // 4
    cout << square(10) << endl; // 100
    write_sorry(); // Sorry
    return 0;
}

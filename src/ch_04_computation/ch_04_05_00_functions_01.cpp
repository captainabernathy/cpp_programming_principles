// program demonstrates the implementation of few simple inline functions

#include <iostream> // I/O library header

// simple function that squares its input and returns the result
inline int square(int x) { return x * x; }

// simple function that writes "Sorry" to stdout
inline void write_sorry() { std::cout << "Sorry" << '\n'; }

int main()
{
    using std::cout;

    cout << square(2) << '\n'; // 4
    cout << square(10) << '\n'; // 100
    write_sorry(); // Sorry
    return 0;
}

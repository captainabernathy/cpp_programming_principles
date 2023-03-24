// program writes "Hello, World!" to stdout and waits for the user to
// enter a character before terminating

#include <iostream> // I/O library header
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std; // add names from std namespace to global namespace

int main()
{
    cout << "Hello, World!\n"; // write "Hello, World!" to stdout
    keep_window_open(); // wait for user to enter a character
    return 0;
}

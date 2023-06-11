// program writes "Hello, World!" to stdout and waits for the user to
// enter a character before terminating

#include <iostream> // for cout
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open()

int main()
{
    using std::cout;

    cout << "Hello, World!\n"; // writes "Hello, World!" to stdout
    cout << "Press any key to exit...\n";
    keep_window_open(); // waits for user to enter a character

    return 0;
}

// program prompts user to enter text and reports when the user enters the same
// word twice in succession

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::string;
    using std::cout;
    using std::cin;

    // string to hold the previous word read from stdin
    string prev = " "; // initialize prev to a string containing a single space

    // string to hold the current word read from stdin
    string cur;

    cout << "Enter text or CTRL-D to exit: ";
    while (cin >> cur)
    {
        // test if the current and previously entered words are the same and
        // write result to stdout when they are
        if (prev == cur)
            cout << "repeated word: " << cur << '\n';

        prev = cur; // set cur to prev... then read into cur in the loop test
    }

    return 0;
}

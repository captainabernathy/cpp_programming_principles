// program prompts user to enter text, reports when the user enters the same
// word twice in succession, and counts the number of words entered

#include <iostream> // for cin, cout
#include <string> // for string

int main()
{
    using std::cout;
    using std::string;
    using std::cin;

    int words = 0; // initialize word counter
   
    // string to hold the previous word read from stdin
    string prev = " "; // initialize prev to a string containing a single space
    
    // string to hold the current word read from stdin
    string cur;

    cout << "Enter text or CTRL-D to exit: ";
    while (cin >> cur)
    {
        ++words; // increase word count
        
        // test if the current and previously entered words are the same and
        // write result to stdout when they are
        if (prev == cur)
            cout << "word number " << words << " repeated: " << cur << '\n';
        
        prev = cur; // set cur to prev... then read into cur in the loop test
    }

    return 0;
}

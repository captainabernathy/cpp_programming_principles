#include <iostream> // I/O library header
#include <cstring> // provides string.h to manipulate C strings and arrays
using namespace std;  // add names from std namespace to global namespace

// given a pointer to the first and last characters in a string, function
// returns whether or not the string is a palindrome
bool is_palindrome(const char *first, const char *last);

// function reads at most max-1 characters from is into buffer, which will be
// null-terminated
istream& read_word(istream& is, char *buffer, int max);

int main()
{
    constexpr int max = 128; // buffer size
    char s[max]; // buffer

    cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    while (read_word(cin, s, max))
    {
        cout << s << " is";
        if (!is_palindrome(&s[0], &s[strlen(s) - 1])) // test input
            cout << " not";
        cout << " a palindrome" << endl << endl;

        cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    }

    return 0;
}

istream& read_word(istream& is, char *buffer, int max)
{
    is.width(max); // read at most max-1 characters in the next input operation
    is >> buffer; // read whitespace-terminated word, and add \0 after the last
                  // character read into the buffer
    return is;
}

bool is_palindrome(const char *first, const char *last)
{
    // recursively increment pointer address from first and decrement it from
    // last... string must be a mirror image of itself to be a palindrome
    return (first < last) ?
            (*first != *last) ? false : is_palindrome(++first, --last) : true;

    // if (first < last)
    // {
    //     if (*first != *last)
    //         return false;
    //     return is_palindrome(++first, --last);
    // }

    // return true;
}

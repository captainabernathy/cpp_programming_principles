// program implements a function that receives pointers to the first and last
// characters of a C-string and recursively determines whether or not it is a
// palindrome

#include <iostream> // for cout, cin, istream
#include <cstring> // for strlen()

// given a pointer to the first and last characters in a string, function
// returns whether or not the string is a palindrome
bool is_palindrome(const char *first, const char *last);

// function reads at most max-1 characters from is into buffer, which will be
// null-terminated
std::istream& read_word(std::istream& is, char *buffer, int max);

int main()
{
    using std::cout;
    using std::cin;

    constexpr int max = 128; // buffer size
    char s[max]; // buffer

    cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    while (read_word(cin, s, max))
    {
        cout << s << " is";
        if (!is_palindrome(&s[0], &s[strlen(s) - 1])) // test input
            cout << " not";
        cout << " a palindrome" << "\n\n";

        cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    }

    return 0;
}

std::istream& read_word(std::istream& is, char *buffer, int max)
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

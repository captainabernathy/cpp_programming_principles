// program implements a function that receives a C-string as an array of
// characters and determines whether or not it is a palindrome

#include <iostream> // for istream, cin, cout
#include <cstring> // for strlen()

// given a c-string and its length, function returns whether or not it is a
// palindrome
bool is_palindrome(const char s[], int n);

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
        cout << s << " is"; // test input
        if (!is_palindrome(s, strlen(s)))
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

bool is_palindrome(const char s[], int n)
{
    int first = 0;
    int last = n - 1;

    // cout up from first and down from last...
    // string must be a mirror image of itself to be a palindrome
    while (first < last)
    {
        if (s[first] != s[last])
            return false;
        first++;
        last--;
    }

    return true;
}

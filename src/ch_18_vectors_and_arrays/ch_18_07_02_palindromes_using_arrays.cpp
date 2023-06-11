// program tests an overloaded implementation of the is_palindrome() function,
// which determines whether or not a c-string is a palindrome
//
// program also tests the implementation of the read_word() function, which
// reads characters from an input stream into a buffer as a c-string
//
// bool is_palindrome(const char s[], int n)
// istream& read_word(istream& is, char *buffer, int max)

#include <iostream> // for cin, cout
#include <cstring> // for strlen()
#include <string_utils/string_utils.hpp> // for is_palindrome()
#include <io_utils/io_utils.hpp> // for read_word()

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
        cout << " a palindrome\n";
    }

    return 0;
}

// program implements a function that determines whether or not a string is a
// palindrome

#include <iostream> // I/O library header
#include <string> // string library header

// given a string, function returns whether or not it is a palindrome
bool is_palindrome(std::string const&);

int main()
{
    using std::cout;
    using std::string;
    using std::cin;


    string s;

    cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    while (cin >> s)
    {
        cout << s << " is";
        if (!is_palindrome(s)) // test input
            cout << " not";
        cout << " a palindrome" << "\n\n";
    
        cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    }

    return 0;
}

bool is_palindrome(std::string const& s)
{
    size_t first = 0;
    size_t last = s.length() - 1;

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

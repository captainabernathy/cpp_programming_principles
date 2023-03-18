#include <iostream> // I/O library header
#include <string> // string library header
using namespace std;  // add names from std namespace to global namespace

// given a string, function returns whether or not it is a palindrome
bool is_palindrome(const string&);

int main()
{
    string s;

    cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    while (cin >> s)
    {
        cout << s << " is";
        if (!is_palindrome(s)) // test input
            cout << " not";
        cout << " a palindrome" << endl << endl;
    
        cout << "Enter a string (or CTRL-D to exit): "; // prompt user
    }

    return 0;
}

bool is_palindrome(const string& s)
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

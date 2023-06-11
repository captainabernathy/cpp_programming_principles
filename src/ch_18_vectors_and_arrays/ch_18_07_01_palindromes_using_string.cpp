// program tests the implementation of the is_palindrome() function, which
// determines whether or not a string is a palindrome
//
// bool is_palindrome(string const&)

#include <string> // for string
#include <iostream> // for cin, cout
#include <string_utils/string_utils.hpp> // for is_palindrome()

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
        cout << " a palindrome\n";
    }

    return 0;
}

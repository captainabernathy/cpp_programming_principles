// program demonstrates that reserved words and variable names are
// case-sensitive

#include <iostream> // for cout
#include <string> // for string

int main()
{
    using std::string;
    using std::cout;

    // NOTE: reserved words and variable names are case-sensitive
    // STRING s = "Goodbye cruel world!";
    // cOUT << s << '\n';
    // cout << S << '\n';
    string s = "Goodbye cruel world!";
    cout << s << '\n';

    return 0;
}

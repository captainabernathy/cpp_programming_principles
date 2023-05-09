// program demonstrates that reserved words and variable names are
// case-sensitive

#include <iostream> // I/O library header
#include <string> // string library header

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

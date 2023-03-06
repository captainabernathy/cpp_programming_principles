// program demonstrates that reserved words and variable names are
// case-sensitive

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    // NOTE: reserved words and variable names are case-sensitive
    // STRING s = "Goodbye cruel world!";
    // cOUT << s << endl;
    // cout << S << endl;
    string s = "Goodbye cruel world!";
    cout << s << endl;

    return 0;
}

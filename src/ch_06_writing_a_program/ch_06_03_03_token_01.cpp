#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

class Token
{
public:
    char kind;          // what kind of token
    double value;       // for numbers: a value

    Token(char ch)      // make a Token from a char
        : kind(ch), value(0) { }

    Token(char ch, double val) // make a Token from a char and a double
        : kind(ch), value(val) { }
};

int main()
{
    // create a token from a character
    Token t1('+');  // '+', 0
    
    // create a token from a character and a double
    Token t2('8', 11.5); // '8', 11.5

    // write results to stdout
    cout << "t1: " << t1.kind << ' ' << t1.value << endl; // t1: + 0
    cout << "t2: " << t2.kind << ' ' << t2.value << endl; // t2: 8 11.5

    return 0;
}

// first attempt at defining a Token class to represent the elements of a
// calculator's grammar

#include <iostream> // for cout

// represents a unit in a calculator's grammar
class Token
{
public:
    char kind;          // what kind of token
    double value;       // for numbers: a value

    // constructor for operators and non-numeric values
    Token(char ch)      // make a Token from a char
        : kind {ch}, value {0} { }

    // constructor for numeric values
    Token(char ch, double val) // make a Token from a char and a double
        : kind {ch}, value {val} { }
};

int main()
{
    using std::cout;

    // create a token from a character
    Token t1('+');  // '+', 0
    
    // create a token from a character and a double
    Token t2('8', 11.5); // '8', 11.5

    // write results to stdout
    cout << "t1: " << t1.kind << ' ' << t1.value << '\n'; // t1: + 0
    cout << "t2: " << t2.kind << ' ' << t2.value << '\n'; // t2: 8 11.5

    return 0;
}

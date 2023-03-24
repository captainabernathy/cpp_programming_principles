// first implementation of a Token_stream object to process Tokens as input for
// a calculator program

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

/*
 * Grammar
 *
 * Expression:
 *     Term
 *     Expression "+" Term
 *     Expression "-" Term
 *
 * Term:
 *     Primary
 *     Term "*" Primary
 *     Term "/" Primary
 *
 * Primary:
 *     Number
 *     "(" Expression ")"
 *
 * Number:
 *     floating-point literal
 */

// Token: <kind, value>
// represents a unit in a calculator's grammar
class Token {
public:
    char kind;      // what kind of token
    double value;   // for numbers: a value

    // constructor for operators and non-numeric values
    Token(char ch)  // make a Token from a char
        : kind(ch), value(0) {  }

    // constructor for numeric values
    Token(char ch, double val)  // make a Token from a char and a double
        : kind(ch), value(val) {  }
};

// A Token_stream object reads characters from stdin and presents the program
// with the next token when it asks for it
class Token_stream {
public:
    Token_stream(); // default constructor
    Token get();    // get a Token <kind, val>
    void putback(Token t);  // put a Token <kind, val> back

// private:
    bool full;      // is there a Token in the buffer?
    Token buffer;   // stores a Token put back (returned) from putback()
};

// construct a Token_stream that indicates that the buffer is empty
Token_stream::Token_stream()
    : full(false), buffer(0) {  }

// putback() member function puts its argument back into Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full) // we can't put a token back into a full Token_stream
        error("putback() into a full buffer");
    buffer = t;     // write t <kind, val> to Token_stream's buffer;
    full = true;    // indicate Token_stream is full
}

int main()
{
    try
    {
        // create a Token_stream
        Token_stream ts;    // calls default constructor
        
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << endl;

        // put Token <')', ascii_val> into Token_stream ts
        ts.putback(')');
        
        // kind: ASCII for ), value: ASCII for ), full: true
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << endl;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!" << endl;
        return 2;
    }

    return 0;
}

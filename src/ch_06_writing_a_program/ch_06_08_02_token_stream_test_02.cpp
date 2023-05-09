// second implementation of a Token_stream object to process Tokens as input
// for a calculator program

#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing helper functions

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

// represents a unit in a calculator's grammar
class Token {
public:
    char kind;        // what kind of token
    double value;       // for numbers: a value

    // constructor for operators and non-numeric values
    explicit Token(char ch)      // make a Token from a char
        : kind {ch}, value {0} {  }

    // constructor for numeric values
    Token(char ch, double val)  // make a Token from a char and a double
        : kind {ch}, value {val} {  }
};

// A Token_stream object reads characters from stdin and presents the program
// with the next token when it asks for it
class Token_stream {
public:
    // constructor initializes this Token_stream to full to indicate its
    // buffer is empty
    Token_stream()         // make a Token_stream that reads from cin
        : full {false}, buffer {0} {  }

    // get() returns a Token from this Token_stream
    Token get();            // get a Token

    // putback() member function puts a Token back into this
    // Token_stream's buffer
    void putback(Token t);  // put a Token back

// private:
    bool full;          // is there a Token in the buffer?
    Token buffer;       // stores a Token put back (returned) from putback()
};

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        Token_stream ts; // create a Token_stream
       
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        Token t(')'); // create a token
        ts.putback(t); // put token back into Token_stream t

        // kind: ASCII for ), value: ASCII for ), full: true
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // read token from Token_stream t's Token buffer
        Token u = ts.get();

        // kind: ASCII for ), value: ASCII for ), full: false
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // test Token t and u's attributes for equality
        // if (u.kind != t.kind || u.value != t.value)
        if (!(u.kind == t.kind && u.value == t.value))
            error("Error in token stream logic");
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!" << '\n';
        return 2;
    }
}

// putback() member function puts a Token back into this Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full) // we can't put a token back into a full Token_stream
        error("putback() into a full buffer");
    buffer = t;     // write t into buffer
    full = true;    // indicate Token_stream is full
}

// get() gets a Token from this Token_stream
Token Token_stream::get()
{
    if (full)    // do we already have a Token ready?
    {
        full = false; // indicate this Token_stream's buffer is empty
        return buffer; // return this Token_stream's buffer
    }

    char ch;
    std::cin >> ch;  // cin ignores whitespace (' ', '\n', '\t', ...)

    // evaluate character
    switch (ch)
    {
        // let each of these characters represent itself
        case ';':   // for "print"
        case 'q':   // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);   // return a new Token
        // numeric characters
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            {
                // put numeric character back into input stream
                std::cin.putback(ch);
                double val;
                std::cin >> val;     // read a floating-point number
                // let '8' represent "a number"
                return Token('8', val); // return a new Token
            }
        // unrecognized token
        default:
            error("Bad token");
    }
}

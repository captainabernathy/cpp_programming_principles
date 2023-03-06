#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.h" // project header containing helper functions
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
class Token {
    public:
        double kind;        // what kind of token
        double value;       // for numbers: a value

        Token(char ch)      // make a Token from a char
            : kind(ch), value(0){  }

        Token(char ch, double val)  // make a Token from a char and a double
            : kind(ch), value(val){  }
};

class Token_stream {
    public:
        Token_stream();         // make a Token_stream that reads from cin
        Token get();            // get a Token <kind, val>
        void putback(Token t);  // put a Token <kind, val> back

    // private:
        bool full;          // is there a Token <kind, val> in the buffer?
        Token buffer;       // stores a Token put back (returned) from putback()
};

// construct a Token_stream that indicates that the buffer is empty
Token_stream::Token_stream()
    : full(false), buffer(0){  }

// putback() member function puts its argument back into Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full) // we can't put a token back into a full Token_stream
        error("putback() into a full buffer");
    buffer = t;     // write t <kind, val> into buffer
    full = true;    // indicate Token_stream is full
}

// get() gets a Token <kind, val> from a Token_stream
Token Token_stream::get()
{
    if (full)    // do we already have a Token ready?
    {
        full = false; // indicate buffer is empty
        return buffer; // return  Token_stream's buffer (Token<kind, value>)
    }

    char ch;
    cin >> ch;  // cin ignores whitespace (' ', '\n', '\t', ...)

    // evaluate character
    switch (ch)
    {
        // let each of these characters represent itself
        case ';':   // for "print"
        case 'q':   // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);   // return new Token <ch,0>
        // numeric characters
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            {
                // put numeric Token<ch, val>  back into input stream
                cin.putback(ch);
                double val;
                cin >> val;     // read a floating-point number
                // let '8' represent "a number"
                return Token('8', val); // return Token<'8', val>
            }
        // unrecognized token
        default:
            error("Bad token");
    }
}

int main()
{
    try
    {
        Token_stream ts; // create a Token_stream
       
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << endl;

        Token t(')'); // create a token
        ts.putback(t); // put token back into Token_stream t

        // kind: ASCII for ), value: ASCII for ), full: true
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << endl;

        // read token from Token_stream t's Token buffer
        Token u = ts.get();

        // kind: ASCII for ), value: ASCII for ), full: false
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << endl;

        // test Token t and u's attributes for equality
        // if (u.kind != t.kind || u.value != t.value)
        if (!(u.kind == t.kind && u.value == t.value))
            error("Error in token stream logic");
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
}

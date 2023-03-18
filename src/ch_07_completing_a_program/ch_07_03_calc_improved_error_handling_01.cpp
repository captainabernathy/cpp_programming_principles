#include <iostream>
#include <stdexcept>
#include "std_lib_facilities.h"
using namespace std;

/*
 *  Grammar
 *
 *  Expression:
 *      Term
 *      Expression + Term
 *      Expression - Term
 *
 *  Term:
 *      Primary
 *      Term * Primary
 *      Term / Primary
 *
 *  Primary:
 *      Number
 *      ( Expression )
 *
 *  Number:
 *      floating-point literal
 */

// Token: <kind, value>
class Token {
    public:
        char kind;          // what kind of token
        double value;       // for numbers: a value

        Token(char ch)      // make a Token from a char
            : kind(ch), value(0) { }

        Token(char ch, double val) // make a Token from a char and a double
            : kind(ch), value(val) {  }
};

class Token_stream {
    public:
        Token_stream();     // make a Token_stream that reads from cin
        Token get();        // get a Token<kind, value>
        void putback(Token t);  // put a Token<kind, value> back

    private:
        bool full;          // is there a Token in the buffer?
        Token buffer;       // stores a Token put back (returned) from putback()
};

// constructor initializes a Token_stream to full to indicate the buffer is empty
Token_stream::Token_stream()
    : full(false), buffer(0){  }


// putback() member function puts its argument back into Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;     // write t <kind, value> to Token_stream's buffer
    full = true;    // indicate Token_stream is full
}

// get() returns a Token<kind, value> from a Token_stream
Token Token_stream::get()
{
    if (full)    // do we already have a Token ready?
    {
        full = false;   // indicate buffer is not full
        return buffer;  // return  Token_stream's buffer (Token<kind, value>)
    }

    char ch;
    cin >> ch;  // cin skips whitespace (' ', '\t', '\n', etc)

    // evaluate character
    switch (ch)
    {
        // let each of these characters represent itself
        case ';':   // for print
        case 'q':   // for quit
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);  // return Token<ch, 0>
        // numeric characters
        case '.': case '1': case '2': case '3': case '4': case '5': case '6':
        case '7': case '8': case '9':
            {
                // put Token<ch, val> back into input stream
                cin.putback(ch);
                double val;
                cin >> val;         // read floating-point number
                // let '8' represent "a number"
                return Token('8', val); // return Token<'8', val>
            }
        // unrecognized token
        default:
            error("Bad token");
    }
}


// default constructed Token_stream... provides get(), putback()
Token_stream ts;

double expression(); // forward declaration so primary() can call expression()

// primary() deals with numbers and parentheses
// In grammar...
// Primary:
//  Number
//  "(" Expression ")"
double primary()
{
    // read a Token <kind, val> from Token_stream ts's buffer into t
    Token t = ts.get();

    // evalute kind of token received
    switch (t.kind)
    {
        // parenthetical expression
        case '(':
            {
                // expression() puts a ')' back into Token_stream back after
                // reading an expression
                double d = expression(); // evaluate expression in parentheses
                
                // read a Token <kind, val> from Token_stream ts's buffer into t
                t = ts.get();

                // expression must end with a closed parentheses
                if (t.kind != ')')
                    error("')' expected"); // invalid expression
                return d; // return the result of the expression
            }
        // '8' represents a numeric token
        case '8':
            return t.value; // return token's value
        default:
            error("primary expected");
    }
}

// term() deals with *, /
// In grammar...
// Term:
//  Primary
//  Term "*" Primary
//  Term "/" Primary
double term()
{
    // NOTE: primary can be either a Number or "(" Expression ")"
    double lhs = primary(); // read next token from stream <kind, val>

    // read a Token <kind, val> from Token_stream ts's buffer into t
    Token t = ts.get();

    while (true)
    {
        // evalute kind of token received
        switch (t.kind)
        {
            case '*': // multiplication
                // multiply lhs by rhs and store result in lhs
                lhs *= primary();  // Number or "(" Expression ")"

                // read a Token <kind, val> from Token_stream ts's buffer into t
                t = ts.get();
                break;
            case '/': // division
                {
                    // read rhs of expression
                    double rhs = primary(); // Number or "(" Expression ")"

                    // prohibit division by zero
                    if (rhs == 0)
                        error("divide by zero");

                    // divide lhs by rhs and store result in lhs
                    lhs /= rhs;

                    // read a Token <kind, val> from Token_stream ts's buffer
                    // into t
                    t = ts.get();
                    break;
                }
            default:
                // put t <kind, val> back into Token_stream ts
                ts.putback(t);
                return lhs; // return value of term
        }
    }
}

// expression() deals with + and -
// In grammar...
// Expression:
//  Term
//  Expression "+" Term
//  Expression "-" Term
double expression()
{
    // NOTE: term can be either a Primary, a Term * a Primary, or
    // a Term / a Primary
    double lhs = term(); // term() returns lhs of a primary() (a double value)

    // read a Token <kind, val> from Token_stream ts's buffer into t
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '+': // addition
                // add lhs to the primary() (double) returned from term() and
                // store result in lhs
                lhs += term();

                // read a Token <kind, val> from Token_stream ts's buffer into t
                t = ts.get();
                break;
            case '-': // subtraction
                // subtract lhs from the primary() (double) returned from term()
                // and store result in lhs
                lhs -= term();

                // read a Token <kind, val> from Token_stream ts's buffer into t
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into Token_stream ts
                return lhs; // no more + or - ... return result
        }
    }
}

int main()
{
    try
    {
        while (cin)
        {
            cout << "> ";
            Token t = ts.get();

            while (t.kind == ';')
                t = ts.get();   // eat ;
            if (t.kind == 'q')
            {
                keep_window_open();
                return 0;
            }

            ts.putback(t);
            cout << "= " << expression() << endl;
        }
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "exception " << endl;
        keep_window_open("~~");
        return 2;
    }
}
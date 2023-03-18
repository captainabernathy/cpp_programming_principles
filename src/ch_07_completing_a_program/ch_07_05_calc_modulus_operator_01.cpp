#include <iostream>
#include <stdexcept>
#include "std_lib_facilities.h"
using namespace std;

/*
 *  Grammar
 *
 *  Print:
 *      ;
 *
 *  Quit:
 *      q
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
 *      Term % Primary
 *
 *  Primary:
 *      Number
 *      ( Expression )
 *      -Primary
 *      +Primary
 */

class Token {
    public:
        char kind;
        double value;
        Token(char ch)
            : kind(ch), value(0){  }
        Token(char ch, double d)
            : kind(ch), value(d){  }
};

class Token_stream {
    public:
        Token_stream();
        Token get();  // returns a token...from its buffer or makes one from cin
        void putback(Token t); // puts a Token back into the buffer
    private:
        bool full;  // is there a Token in the buffer?
        Token buffer; // stores a Token put bakc via putback() method
};

Token_stream::Token_stream()
    : full(false), buffer(0){  }

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch)
    {
        case ';': case 'q': case '(': case ')': case '+':  case '-': case '*':
        case '/': case '%':
            return Token(ch);
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token('8', val);
            }
        default:
            error("Bad token");
    }
}

Token_stream ts;
double expression();

// primary() deals with numbers and parentheses
// in grammar
// Primary:
//     Number
//     ( expression )
//     +Primary
//     -Primary
double primary()
{
    Token t = ts.get();

    switch (t.kind)
    {
        case '(':
            {
                double d = expression();
                t = ts.get();
                if (t.kind != ')')
                    error("')' expected");
                return d;
            }
        case '8':
            return t.value;
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}

// term() deals with *, /, and %
// in grammar
// Term:
//     Primary
//     Term * Primary
//     Term / Primary
//     Term % Primary
double term()
{
    double lhs = primary();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '*':
                lhs = primary();
                t = ts.get();
                break;
            case '/':
                {
                    double d = primary();
                    if (d == 0)
                        error("divide by zero");
                    lhs /= d;
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    double d = term();
                    int i_lhs = int(lhs);
                    if (i_lhs != lhs)
                        error("left-hand operator of %% not int");
                    int i_rhs = int(d);
                    if (i_rhs != d)
                        error("right-hand operator of %% not int");
                    if (i_rhs == 0)
                        error("%: divide by zero");
                    lhs = i_lhs % i_rhs;
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);
                return lhs;
        }
    }
}

// expression() deals with + and -
// in grammar
// Expression:
//     Term
//     Expression + Term
//     Expression - Term
double expression()
{
    double lhs = term();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '+':
                lhs += term();
                t = ts.get();
                break;
            case '-':
                lhs -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return lhs;
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
                t = ts.get();
            if (t.kind == 'q')
                return 0;
            ts.putback(t);
            cout << "= " << expression() << endl;
        }

        return 0;
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

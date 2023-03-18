#include <iostream>
#include <stdexcept>
#include <string>
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
 *      +Primary
 *      -Primary
 */

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

class Token {
    public:
        char kind;
        double value;
        Token (char ch)
            : kind(ch), value(0) {  }
        Token (char ch, double val)
            : kind(ch), value(val) {  }
};

class Token_stream {
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream()
    : full(false), buffer(0) {  }

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
        case print: case quit: case '(': case ')': case '+': case '-': case '*':
        case '/': case '%':
            return Token(ch);
        case '.': case '1': case '2': case '3': case '4': case '5': case '6':
        case '7': case '8': case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token(number, val);
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
//     ( Expression )
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
        case number:
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
                lhs *= primary();
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
                    int i_lhs = narrow_cast<int>(lhs);
                    int i_rhs = narrow_cast<int>(term());
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
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
            {
                keep_window_open();
                return 0;
            }

            ts.putback(t);
            cout << result << expression() << endl;
        }

        keep_window_open();
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

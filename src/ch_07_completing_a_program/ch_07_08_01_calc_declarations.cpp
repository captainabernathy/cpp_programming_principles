#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "std_lib_facilities.h"
using namespace std;

/*
 *  Grammar
 *
 *  Calculation:
 *      Statement
 *      Print
 *      Quit
 *      Calculation Statement
 *
 *  Statement:
 *      Declaration
 *      Expression
 *
 *  Declaration:
 *      "let" Name "=" Expression
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
 *      Name
 *      ( Expression )
 *      -Primary
 *      +Primary
 *
 *  Number:
 *      floating-point literal
 */

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const string prompt = "> ";
const string result = "= ";

class Token
{
    public:
        char kind;
        double value;
        string name;
        Token(char ch)
            : kind(ch), value(0) { }
        Token(char ch, double val)
            : kind(ch), value(val) { }
        Token(char ch, string str)
            : kind(ch), name(str) { }
};

class Token_stream {
    public:
        Token_stream();
        Token get();
        void putback(Token t);
        void ignore(char ch);
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream()
    : full(false), buffer(0) { }

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
        case quit: case print: case '(': case ')': case '+': case '-': case '*':
        case '/': case '%': case '=':
            return Token(ch);
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token(number, val);
            }
        default:
            if (isalpha(ch))
            {
                cin.putback(ch);
                string s;
                cin >> s;

                if (s == declkey)
                    return Token(let);  // key let
                return Token(name, s);
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char ch)
{
    // c represents the kind of a Token...
    // first look in buffer
    if (full && ch == buffer.kind)
    {
        full = false;
        return;
    }

    full = false;

    // now search input
    char c = 0;
    while (cin >> c)
        if (c == ch)
            return;
}

Token_stream ts;

class Variable {
    public:
        string name;
        double value;
        Variable(string n, double v)
            : name(n), value(v){ }
};

vector<Variable> var_table;

// return the value of the Variable s
double get_value(string s)
{
    for (size_t i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
            return var_table[i].value;

    error("get: undefined variable ", s);
}


// is var already in var_table
bool is_declared(string var)
{
    for (size_t i = 0; i < var_table.size(); i++)
        if (var_table[i].name == var)
            return true;

    return false;
}

// add(var, value) to var_table
double define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");

    var_table.push_back(Variable(var, val));
    return val;
}

double expression();

// primary() deals with numbers and parentheses
// in grammar
// Primary:
//     Number
//     Name
//     ( Expression )
//     -Primary
//     +Primary
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
        case name:
            return get_value(t.name);
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
                    lhs /= primary();
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    int i_lhs = narrow_cast<int>(lhs);
                    int i_rhs = narrow_cast<int>(term());
                    if (i_rhs == 2)
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

// expression()
// deals with + and -
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

// handles name = expression
// in grammar
// "let" name "=" expression
double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");

    string var_name = t.name;

    Token eq = ts.get();
    if (eq.kind != '=')
        error("= missing in the declaration of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

// statement()
// in grammar
// Statement:
//     Declaration
//     Expression
double statement()
{
    Token t = ts.get();

    switch (t.kind)
    {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();

            while (t.kind == print)
                t = ts.get();   // first discard all "prints"

            if (t.kind == quit)
                return; // quit

            ts.putback(t);
            cout << result << statement() << endl;
        }
        catch (exception& ex)
        {
            cerr << ex.what() << endl;
            clean_up_mess();
        }
}

int main()
{
    try
    {
        calculate();
        keep_window_open();
        return 0;
    }
    catch (runtime_error& ex)
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

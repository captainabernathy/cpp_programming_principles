// program loads predefined values for e and pi into the calculator

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <cctype> // for isalpha(), isdigit()
#include <string> // for string
#include <vector> // for vector
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open(),
                                                 // narrow_cast<>, error()

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

// some symbolic constants to reduce the number of hard-coded values
const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const std::string declkey = "let";
const std::string prompt = "> ";
const std::string result = "= ";

// represents a unit in a calculator's grammar
class Token
{
public:
    char kind; // what kind of token
    double value; // for numbers: a value
    std::string name; // for declarations: a name
    
    // constructor for operators and non-numeric values
    Token(char ch)
        : kind {ch}, value {0} { }
    
    // constructor for numeric values
    Token(char ch, double val)
        : kind {ch}, value {val} { }

    // constructor for declarations
    Token(char ch, std::string str)
        : kind {ch}, name {str} { }
};

// A Token_stream object reads characters from stdin and presents the program
// with the next token when it asks for it
class Token_stream {
public:
    // constructor initializes a Token_stream to full to indicate the buffer
    // is empty
    Token_stream()      // make a Token_stream that reads from cin
        : full {false}, buffer {0} {  }

    // get() returns a Token from a Token_stream
    Token get();        // get a Token
    
    // putback() member function puts its argument back into Token_stream's
    // buffer
    void putback(Token t);  // put a Token back

    // discard characters up to and including ch in this Token_stream
    // ch represents the kind of Token
    void ignore(char ch);

private:
    bool full; // is there a Token in the buffer?
    Token buffer; // stores a Token put back (returned) from putback()
};

// class that represents a variable as string and a double
class Variable {
    public:
        std::string name;
        double value;
        
        // construct a variable with name n and value v
        Variable(std::string n, double v)
            : name {n}, value {v} { }
};

// statement()
// in grammar
// Statement:
//     Declaration
//     Expression
double statement();

// handles name = expression
// in grammar
// Declaration:
//      "let" Name "=" Expression
double declaration();

// expression() deals with + and -
// In grammar...
// Expression:
//      Term
//      Expression "+" Term
//      Expression "-" Term
double expression();

// term() deals with *, /, and %
// in grammar
// Term:
//     Primary
//     Term * Primary
//     Term / Primary
//     Term % Primary
double term();

// primary() deals with numbers and parentheses
// in grammar
// Primary:
//     Number
//     Name
//     ( Expression )
//     -Primary
//     +Primary
double primary();

// default constructed Token_stream... provides get(), putback(), and ignore()
Token_stream ts;

// table of variables
std::vector<Variable> var_table;

// returns the value of a Variable named var in var_table or calls error() if
// var is not defined in var_table
double get_value(std::string var);

// set the value of a Variable named var in var_table to val or calls error if
// var is not defined in var_table
void set_value(std::string var, double val);

// returns true when a Variable named var is already in var_table, false
// otherwise
bool is_declared(std::string var);

// add a Variable named var with value val in var_table and returns val or
// calls error() if a variable named var already exists in var_table
double define_name(std::string var, double val);

// performs the calculation loop
void calculate();

// discard everything in ts up to and include ';'
inline void clean_up_mess()
{
    ts.ignore(print);
}

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);
        calculate();
        keep_window_open();
        return 0;
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
}

// putback() member function puts a Token back into this Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t; // write t to this Token_stream's buffer
    full = true; // indicate that this Token_stream is full
}

// get() returns a Token from this Token_stream
Token Token_stream::get()
{
    if (full) // do we already have a Token ready?
    {
        full = false; // indicate buffer is not full
        return buffer; // return the Token in this Token_stream's buffer
    }

    char ch;
    std::cin >> ch; // cin skips whitespace (' ', '\t', '\n', etc)

    // evaluate character
    switch (ch)
    {
        // let each of these characters represent itself
        case print: case quit: case '(': case ')': case '+': case '-': case '*':
        case '/': case '%': case '=':
            return Token(ch);
        // numeric characters
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            {
                // put character back into input stream
                std::cin.putback(ch);
                double val;
                std::cin >> val; // read floating-point number
                return Token(number, val);
            }
        default:
            if (isalpha(ch)) // check if ch is a letter
            {
                std::string s;
                s += ch; // concatenate the first letter to s

                // read subsequent letters and/or numbers in the declaration
                while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch; // build up
                
                // put character back into input stream
                std::cin.putback(ch);

                // check if s was a declaration "let"
                if (s == declkey)
                    return Token(let);

                return Token(name, s); // s muct be a name
            }
            // unrecognized token
            error("Bad token");
    }
}

// discard characters up to and including ch in this Token_stream
// ch represents the kind of Token
void Token_stream::ignore(char ch)
{
    // first look in the buffer for ch
    if (full && ch == buffer.kind)
    {
        full = false; // indicate buffer is not full
        return;
    }

    full = false; // indicate buffer is not full

    char c = 0;
    while (std::cin >> c) // search input until we find ch
        if (c == ch)
            return;
}

// statement()
// in grammar
// Statement:
//     Declaration
//     Expression
double statement()
{
    // read a Token from Token_stream ts's buffer into t
    Token t = ts.get();

    // evaluate t
    switch (t.kind)
    {
        case let: // L... statement is a declaration
            return declaration();
        default:
            ts.putback(t); // put t back into Token_stream ts
            return expression(); // statement is an expression
    }
}

// handles name = expression
// in grammar
// Declaration:
//      "let" Name "=" Expression
double declaration()
{
    // read a Token from Token_stream ts's buffer into t
    Token t = ts.get();
    
    // evalute t
    if (t.kind != name) // t.kind != 'a'
        error("name expected in declaration");

    std::string var_name = t.name; // set variable's name

    // read a Token from Token_stream ts's buffer into eq
    Token eq = ts.get();
    if (eq.kind != '=')
        error("= missing in the declaration of ", var_name);

    double d = expression(); // evaluate expression

    // add variable and value to variable table
    define_name(var_name, d);
    return d; // return value
}

// expression() deals with + and -
// In grammar...
// Expression:
//      Term
//      Expression "+" Term
//      Expression "-" Term
double expression()
{
    // NOTE: term can be either a Primary, a Term * a Primary, or
    // a Term / a Primary
    double lhs = term(); // term() returns lhs of a primary() (a double value)

    // read a Token from Token_stream ts's buffer into t
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '+': // addition
                // add lhs to the primary() (double) returned from term() and
                // store result in lhs
                lhs += term();

                // read a Token from Token_stream ts's buffer into t
                t = ts.get();
                break;
            case '-': // subtraction
                // subtract lhs from the primary() (double) returned from term()
                // and store result in lhs
                lhs -= term();

                // read a Token from Token_stream ts's buffer into t
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into Token_stream ts
                return lhs; // no more + or - ... return result
        }
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
    // NOTE: primary can be either a Number or "(" Expression ")"
    double lhs = primary(); // read next token from stream

    // read a Token from Token_stream ts's buffer into t
    Token t = ts.get();

    while (true)
    {
        // evalute kind of token received
        switch (t.kind)
        {
            case '*': // multiplication
                // multiply lhs by rhs and store result in lhs
                lhs *= primary();  // Number or "(" Expression ")"

                // read a Token from Token_stream ts's buffer into t
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

                    // read a Token from Token_stream ts's buffer into t
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    /// cast left hand side of modulus expression to int
                    int i_lhs = narrow_cast<int>(lhs);

                    // evaluate right hand term of modulus expression
                    int i_rhs = narrow_cast<int>(term());

                    if (i_rhs == 0) // prohibit division by zero
                        error("%: divide by zero");

                    // perform modulus operation and store result in lhs
                    lhs = i_lhs % i_rhs;
                    
                    // read a Token from Token_stream ts's buffer into t
                    t = ts.get();
                    break;
                }
            default:
                // put t back into Token_stream ts
                ts.putback(t);
                return lhs; // return value of term
        }
    }
}

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
    // read a Token from Token_stream ts's buffer into t
    Token t = ts.get();

    // evalute kind of token received
    switch (t.kind)
    {
        // parenthetical expression
        case '(':
            {
                // expression() puts a ')' back into a Token_stream after
                // reading an expression
                double d = expression(); // evaluate expression in parentheses
                
                // read a Token from Token_stream ts's buffer into t
                t = ts.get();

                // expression must end with a closed parentheses
                if (t.kind != ')')
                    error("')' expected"); // invalid expression
                return d; // return the result of the expression
            }
        case number:
            return t.value; // return token's value
        case name:
            return get_value(t.name); // return value of variable with t's name
        // unary -
        case '-':
            return -primary(); // recur
        // unary +
        case '+':
            return primary(); // recur
        default:
            error("primary expected");
    }
}

// returns the value of a Variable named var in var_table or calls error() if
// var is not defined in var_table
double get_value(std::string var)
{
    // loop over the Variables in var_table
    for (size_t i = 0; i < var_table.size(); i++)
        // look for a Variable with a name that is the same as var and return
        // its value if found
        if (var_table[i].name == var)
            return var_table[i].value;

    error("get: undefined variable ", var); // var isn't defined in var_table
}

// set the value of a Variable named var in var_table to val or calls error if
// var is not defined in var_table
void set_value(std::string var, double val)
{
    // loop over the Variables in var_table
    for (size_t i = 0; i < var_table.size(); i++)
        // look for a Variable with a name that is the same as var and set its
        // value to val if found
        if (var_table[i].name == var)
        {
            var_table[i].value = val;
            return;
        }

    error("set: undefined variable ", var); // var isn't defined in var_table
}

// returns true when a Variable named var is already in var_table, false
// otherwise
bool is_declared(std::string var)
{
    // look for a Variable in var_table with a name that is the same as var
    for (size_t i = 0; i < var_table.size(); i++)
        if (var_table[i].name == var)
            return true; // found

    return false; // no Variable with the same name as var exists in var_table
}

// add a Variable named var with value val in var_table and returns val or
// calls error() if a variable named var already exists in var_table
double define_name(std::string var, double val)
{
    if (is_declared(var)) // search for var in var_table
        error(var, " declared twice");

    var_table.push_back(Variable(var, val)); // add new Variable to var_table
    return val;
}

// performs the calculation loop
void calculate()
{
    while (std::cin)
        try
        {
            std::cout << prompt; // output prompt
            Token t = ts.get(); // get a token

            while (t.kind == print)
                t = ts.get();   // first discard all "prints"

            if (t.kind == quit)
                return; // quit

            // put t back into Token_stream ts's buffer and
            // indicate that buffer is full
            ts.putback(t);
            std::cout << result << statement() << '\n';
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what() << '\n';
            clean_up_mess();
        }
}

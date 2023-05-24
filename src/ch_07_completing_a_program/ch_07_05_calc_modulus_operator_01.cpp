// program adds the ability to use the modulus operator in the calculator

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open(),
                                                 // error()

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
 *
 *  Number:
 *      floating-point literal
 */

// represents a unit in a calculator's grammar
class Token {
public:
    char kind; // what kind of token
    double value; // for numbers: a value

    // constructor for operators and non-numeric values
    Token(char ch) // make a Token from a char
        : kind {ch}, value {0} { }

    // constructor for numeric values
    Token(char ch, double val) // make a Token from a char and a double
        : kind {ch}, value {val} {  }
};

// A Token_stream object reads characters from stdin and presents the program
// with the next token when it asks for it
class Token_stream {
public:
    // constructor initializes this Token_stream to full to indicate its
    // buffer is empty
    Token_stream() // make a Token_stream that reads from cin
        : full {false}, buffer {0} {  }

    // get() returns a Token from this Token_stream
    Token get(); // get a Token
    
    // putback() member function puts a Token back into this
    // Token_stream's buffer
    void putback(Token t); // put a Token back

private:
    bool full; // is there a Token in the buffer?
    Token buffer; // stores a Token put back (returned) from putback()
};

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

// primary() deals with numbers, parentheses, and unary + and -
// in grammar
// Primary:
//     Number
//     "(" Expression ")"
//     -Primary
//     +Primary
double primary();

// default constructed Token_stream... provides get(), putback()
Token_stream ts;

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cin;
        using std::cout;

        while (cin)
        {
            cout << "> "; // prompt
            Token t = ts.get(); // get a token
            
            // evaluate a token
            while (t.kind == ';')
                t = ts.get(); // eat ';'

            if (t.kind == 'q') // 'q' for quit
            {
                keep_window_open();
                return 0;
            }
            
            // put t back into Token_stream ts's buffer and
            // indicate that buffer is full
            ts.putback(t);
            cout << "= " << expression() << '\n';
        }

        keep_window_open();
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "exception " << '\n';
        keep_window_open("~~");
        return 2;
    }

    return 0;
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
        return buffer; // return this Token_stream's buffer
    }

    char ch;
    std::cin >> ch; // cin skips whitespace (' ', '\t', '\n', etc)

    // evaluate character
    switch (ch)
    {
        // let each of these characters represent itself
        case ';': case 'q': case '(': case ')': case '+':  case '-': case '*':
        case '/': case '%':
            return Token(ch);
        // numeric characters
        case '.': case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            {
                // put character back into input stream
                std::cin.putback(ch);
                double val;
                std::cin >> val; // read floating-point number
                // let '8' represent "a number"
                return Token('8', val);
            }
        // unrecognized token
        default:
            error("Bad token");
    }
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
                    double d = term(); // evaluate term

                    int i_lhs = int(lhs); // cast left hand side to int
                    if (i_lhs != lhs) // must have an int on the left hand side
                        error("left-hand operator of %% not int");

                    int i_rhs = int(d); // cast right hand side to int
                    if (i_rhs != d) // must have int on right hand side
                        error("right-hand operator of %% not int");

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

// primary() deals with numbers, parentheses, and unary + and -
// in grammar
// Primary:
//     Number
//     "(" Expression ")"
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
        // '8' represents a numeric token
        case '8':
            return t.value; // return token's value
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

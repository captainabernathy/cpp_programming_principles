// first implementation of a Token_stream object to process Tokens as input for
// a calculator program

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

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
    char kind;      // what kind of token
    double value;   // for numbers: a value

    // constructor for operators and non-numeric values
    Token(char ch)  // make a Token from a char
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
    Token_stream() // default constructor
        : full {false}, buffer {0} {  }
    
    // get() returns a Token from this Token_stream
    Token get();    // get a Token
    
    // putback() member function puts its argument back into this
    // Token_stream's buffer
    void putback(Token t);  // put a Token back

// private:
    bool full;      // is there a Token in the buffer?
    Token buffer;   // stores a Token put back (returned) from putback()
};


int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        // create a Token_stream
        Token_stream ts;    // calls default constructor
        
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // put Token <')', ascii_val> into Token_stream ts
        ts.putback(Token(')'));
        
        // kind: ASCII for ), value: ASCII for ), full: true
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';
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

    return 0;
}

// putback() member function puts a Token back into this Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full) // we can't put a token back into a full Token_stream
        error("putback() into a full buffer");
    buffer = t;     // write t to this Token_stream's buffer;
    full = true;    // indicate this Token_stream is full
}

#ifndef TOKEN_STREAM_HPP
#define TOKEN_STREAM_HPP

#include <calculator_utils/token.hpp> // for Token

// A Token_stream object reads characters from stdin and presents the program
// with the next token when it asks for it
class Token_stream {
public:
    // constructor initializes this Token_stream to full to indicate its
    // buffer is empty
    Token_stream() // make a Token_stream that reads from cin
        : full {false},
          buffer {0} { }
   
    // returns a Token from this Token_stream
    Token get(); // get a Token
    
    // puts t back into this Token_stream's buffer
    // Token_stream's buffer
    void putback(Token t); // put a Token back

// not defined when a Token_stream supports error recovery
#ifndef NO_IGNORE
    // discard characters up to and including ch in this Token_stream where ch
    // represents the kind of Token
    void ignore(char ch);
#endif

// only defined when an application needs to test a Token_stream's internals
#ifndef TOKEN_STREAM_TEST
private:
#endif

    bool full; // is there a Token in the buffer?
    Token buffer; // stores a Token put back (returned) from putback()
};

#endif

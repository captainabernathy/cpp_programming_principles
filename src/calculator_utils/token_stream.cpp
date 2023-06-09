#include <calculator_utils/token_stream.hpp>

// not defined when a Token_stream supports symbolic constants
#ifndef NO_CONSTANTS
// for number, quit, print, prompt, result
#include <calculator_utils/calculator_constants.hpp>
#endif

// not defined when a Token_stream supports declarations
#ifndef NO_DECL
#include <cctype> // for isalpha(), isdigit()
#include <string> // for string
#endif

#include <iostream> // for cin
#include <cassert> // for assert()
#include <calculator_utils/token.hpp> // for Token
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

//  puts t back into this Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full) // we can't put a token back into this Token_stream if it's full
        error("putback() into a full buffer");
    buffer = t; // write t to this Token_stream's buffer
    full = true; // now indicate that this Token_stream is full
}

// returns a Token from this Token_stream
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
// not defined when a Token_stream supports symbolic constants
#ifndef NO_CONSTANTS
        case print:
        case quit:
#else
        case ';': // for print
        case 'q': // for quit
#endif
        case '(': case ')': case '+': case '-': case '*': case '/':
// not defined with a Token_stream supports the modulus operation
#ifndef NO_MOD
        case '%':
#endif
// not defined when a Token_stream supports declarations
#ifndef NO_DECL
        case '=':
#endif
            return Token {ch}; // return a new Token
        // numeric characters
        case '.': case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                // put numeric character back into input stream
                std::cin.putback(ch);
                double val;
                std::cin >> val; // read floating-point number
// not defined when a Token_stream supports symbolic constants
#ifndef NO_CONSTANTS
                return Token(number, val); // return a new Token
#else
                // let '8' represent "a number"
                return Token('8', val); // return a new Token
#endif
            }
        default:
// not defined when a Token_stream supports declarations
#ifndef NO_DECL
            // check for declaration if ch is a letter
            if (isalpha(ch))
            {
                std::string s;
// not defined when a Token_stream supports Variables
#ifndef NO_VARS
                s += ch; // concatenate the first letter to s
                // read subsequent letters and/or numbers in the declaration
                while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch; // build up

                // put character into input stream
                std::cin.putback(ch);
#else
                // put character into input stream
                std::cin.putback(ch);
                std::cin >> s; // read string from input stream
#endif
                if (s == declkey) // NOTE: declkey == "let"
                    return Token {let}; // NOTE: let == 'L'

                return Token(name, s); // NOTE: name == 'a'
            }
#endif
            // unrecognized token
            error("Bad token");
    }

    assert(0); // should never get here
}

// not defined when a Token_stream supports error recovery
#ifndef NO_IGNORE
// discard characters up to and including ch in this Token_stream where ch
// represents the kind of Token
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
#endif

#ifndef TOKEN_HPP
#define TOKEN_HPP

// not defined when a Token supports declarations
#ifndef NO_DECL
#include <string> // for string
#endif

// a Token represents a unit in a calculator's grammar in terms of a kind,
// value, and name (if declarations are enabled)
class Token {
public:
    char kind; // what kind of token
    double value; // for numbers: a value
// not defined when a Token supports declarations
#ifndef NO_DECL
    std::string name;
#endif

    // constructor for operators and non-numeric values
    // builds a Token from a char
    Token(char ch)
        : kind {ch},
          value {0} { }

    // constructor for numeric values
    // builds a Token from a char and a double
    Token(char ch, double val)
        : kind {ch},
          value {val} { }

// not defined when a Token supports declarations
#ifndef NO_DECL
    // constructor for declarations
    Token(char ch, std::string str)
        : kind {ch},
          name {str} { }
#endif
};

#endif

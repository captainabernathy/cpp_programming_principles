#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

// not defined when a Calculator supports error recovery
#ifndef NO_RECOVERY
#include <calculator_utils/calculator_constants.hpp>
#endif

// not defined when a Calculator supports declarations
#ifndef NO_DECL
#include <calculator_utils/variable.hpp> // for Variable
#include <vector> // for vector
#include <string> // for string
#endif

#include <calculator_utils/token.hpp> // for Token
#include <calculator_utils/token_stream.hpp> // for Token_stream

class Calculator {
public:
    // default constructor
    Calculator() = default;

// not defined when a Calculator handles the computation loop internally
#ifndef NO_CALCULATE
    // performs the calculation loop
    void calculate();
#endif

// not defined when a Calculator supports declarations
#ifndef NO_DECL
    // returns the value of a Variable named var in var_table or calls error()
    // if var is not defined in var_table
    double get_value(std::string var);

    // returns true when a Variable named var is already in var_table, false
    // otherwise
    bool is_declared(std::string var);

    // adds a Variable named var with value val in var_table and returns val or
    // calls error() if a variable named var already exists in var_table
    double define_name(std::string var, double val);
#endif

// not defined when a Calculator supports Variables
#ifndef NO_VARS
    // sets the value of a Variable named var in var_table to val or calls
    // error if var is not defined in var_table
    void set_value(std::string var, double val);
#endif

// only defined when an application needs to test a Calculator's internals
#ifndef CALC_TEST
private:
#endif
    // returns a Token from this Calculator's Token_stream
    Token get()
    {
        return ts.get();
    }

    // puts t back into this Calculator's Token_stream
    void putback(Token t)
    {
        ts.putback(t);
    }

    // expression() deals with + and -
    // In grammar...
    // Expression:
    //      Term
    //      Expression "+" Term
    //      Expression "-" Term
    double expression();

    // primary() deals with numbers and parentheses
    // In grammar...
    // Primary:
    //      Number
    //      "(" Expression ")"
    double primary();

    // term() deals with *, /
    // In grammar...
    // Term:
    //      Primary
    //      Term "*" Primary
    //      Term "/" Primary
    double term();

private:
    Token_stream ts; // a default constructed Token_stream

// not defined when a Calculator supports declarations
#ifndef NO_DECL
    // table of variables
    std::vector<Variable> var_table;

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
#endif

// not defined when a Calculator supports error recovery
#ifndef NO_RECOVERY
    // facilitates recovery from invalid input
    void clean_up_mess()
    {
        ts.ignore(print);
    }
#endif

};

#endif

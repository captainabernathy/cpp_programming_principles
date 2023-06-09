#include <calculator_utils/calculator.hpp>

// not defined when a Calculator supports symbolic constants
#ifndef NO_CONSTANTS
// for number, quit, print, prompt, result
#include <calculator_utils/calculator_constants.hpp>
#endif

// not defined when a Calculator handles the computation loop internally
#ifndef NO_CALCULATE
#include <iostream> // for cout, cin, cerr
#endif

// not defined when a Calculator supports error recovery
#ifndef NO_RECOVERY
#include <exception> // for exception
#endif

// not defined when a Calculator supports declarations
#ifndef NO_DECL
#include <calculator_utils/variable.hpp> // for Variable
#include <string> // for string
#endif

#include <cassert> // for assert()
#include <calculator_utils/token.hpp> // for Token
#include <cpp_facilities/std_lib_facilities.hpp> // for error(), narrow_cast<>

// expression() deals with + and -
// In grammar...
// Expression:
//      Term
//      Expression "+" Term
//      Expression "-" Term
double Calculator::expression()
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
                t = ts.get(); // read next Token
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
double Calculator::term()
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
// not defined with a Calculator supports the modulus operation
#ifndef NO_MOD
            case '%':
                {
                    // cast left hand side of modulus expression to int
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
#endif
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
double Calculator::primary()
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
// not defined when a Calculator supports symbolic constants
#ifndef NO_CONSTANTS
        case number:
            return t.value; // return token's value
#else
        // '8' represents a numeric token
        case '8':
            return t.value; // return token's value
#endif
// not defined when a Calculator supports declarations
#ifndef NO_DECL
        case name:
            return get_value(t.name); // return value of variable with t's name
#endif
// not defined when a Calculator supports the unary + and -
#ifndef NO_UNARY
        // unary -
        case '-':
            return -primary(); // recur
        // unary +
        case '+':
            return primary(); // recur
#endif
        default:
            error("primary expected");
    }

    assert(0); // should never get here
}

// not defined when a Calculator handles the computation loop internally
#ifndef NO_CALCULATE
// performs the calculation loop
void Calculator::calculate()
{
    while (std::cin)
    {
// not defined when a Calculator supports error recovery
#ifndef NO_RECOVERY
        try
        {
#endif
            std::cout << prompt; // output prompt
            Token t = ts.get(); // get a token

            // evaluate a token
            while (t.kind == print)
                t = ts.get();  // first discard all "prints"

            if (t.kind == quit) //  quit
                return;

            // put t back into Token_stream ts's buffer and
            // indicate that buffer is full
            ts.putback(t);
// not defined when a Calculator supports declarations
#ifndef NO_DECL
            std::cout << result << statement() << '\n';
#else
            std::cout << result << expression() << '\n';
#endif
// not defined when a Calculator supports error recovery
#ifndef NO_RECOVERY
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what() << '\n';
            clean_up_mess();
        }
#endif
    }
}
#endif

// not defined when a Calculator supports declarations
#ifndef NO_DECL
// returns the value of a Variable named var in var_table or calls error() if
// var is not defined in var_table
double Calculator::get_value(std::string var)
{
    // loop over the Variables in var_table
    // for (size_t i = 0; i < var_table.size(); i++)
    //     // look for a Variable with a name that is the same as var and return
    //     // its value if found
    //     if (var_table[i].name == var)
    //         return var_table[i].value;

    for (auto v : var_table)
        if (v.name == var)
            return v.value;

    error("get: undefined variable ", var); // var isn't defined in var_table
    assert(0); // should never get here
}

// returns true when a Variable named var is already in var_table, false
// otherwise
bool Calculator::is_declared(std::string var)
{
    // look for a Variable in var_table with a name that is the same as var
    // for (size_t i = 0; i < var_table.size(); i++)
    //     if (var_table[i].name == var)
    //         return true; // found

    for (auto v : var_table)
        if (v.name == var)
            return true;

    return false; // no Variable with the same name as var exists in var_table
}

// adds a Variable named var with value val in var_table and returns val or
// calls error() if a variable named var already exists in var_table
double Calculator::define_name(std::string var, double val)
{
    if (is_declared(var)) // search for var in var_table
        error(var, " declared twice");

    var_table.push_back(Variable(var, val)); // add new Variable to var_table
    return val;
}

// handles name = expression
// in grammar
// Declaration:
//      "let" Name "=" Expression
double Calculator::declaration()
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

// statement()
// in grammar
// Statement:
//     Declaration
//     Expression
double Calculator::statement()
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
#endif

// not defined when a Calculator supports Variables
#ifndef NO_VARS
// sets the value of a Variable named var in var_table to val or calls error if
// var is not defined in var_table
void Calculator::set_value(std::string var, double val)
{
    // loop over the Variables in var_table
    // for (size_t i = 0; i < var_table.size(); i++)
    //     // look for a Variable with a name that is the same as var and set its
    //     // value to val if found
    //     if (var_table[i].name == var)
    //     {
    //         var_table[i].value = val;
    //         return;
    //     }

    for (auto v : var_table)
        if (v.name == var)
        {
            v.value = val;
            return;
        }

    error("set: undefined variable ", var); // var isn't defined in var_table
}
#endif

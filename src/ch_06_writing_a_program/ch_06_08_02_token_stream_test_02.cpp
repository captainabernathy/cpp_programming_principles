// program tests implementation of a Token_stream class for processing Tokens
// as input for a calculator program

// to make private Token_stream attributes visible for testing
#ifndef TOKEN_STREAM_TEST
#define TOKEN_STREAM_TEST
#endif

#include <iostream> // for cout, cerr
#include <exception> // for exception
#include <calc/token.hpp> // for Token
#include <calc/token_stream.hpp> // for Token_stream
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

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        Token_stream ts; // create a Token_stream
       
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        Token t {')'}; // create a token
        ts.putback(t); // put token back into Token_stream t

        // kind: ASCII for ), value: ASCII for ), full: true
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // read token from Token_stream t's Token buffer
        Token u = ts.get();

        // kind: ASCII for ), value: ASCII for ), full: false
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // test Token t and u's attributes for equality
        // if (u.kind != t.kind || u.value != t.value)
        if (!(u.kind == t.kind && u.value == t.value))
            error("Error in token stream logic");
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}


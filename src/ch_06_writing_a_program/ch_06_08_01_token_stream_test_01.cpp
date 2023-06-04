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

        // create a Token_stream
        Token_stream ts; // calls default constructor
        
        // kind: 0, value: 0, full: 0
        cout << "kind: " << ts.buffer.kind << " "
            << "value: " << ts.buffer.value << " "
            << "full: " << ts.full << '\n';

        // put Token <')', ascii_val> into Token_stream ts
        ts.putback(Token {')'});
        
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
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}


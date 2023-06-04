// program tests the implementation of the Calculator class, which encapsulates
// a Token_stream object to process the Tokens it receives
//
// NOTE: This program and ch_06_09_token_stream_02 are the same

// to make private Calculator attributes visible for testing
#ifndef CALC_TEST
#define CALC_TEST
#endif

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calc/token.hpp> // for Token
#include <calc/calculator.hpp> // for Calculator

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
    using std::exception;
    using std::cerr;

    try
    {
        using std::cin;
        using std::cout;

        Calculator c;
        double val = 0;

        while (cin)
        {
            // read a Token from c into t
            Token t = c.get();

            if (t.kind == 'q') // 'q' for quit
                return 0;
            if (t.kind == ';') // ';' for print
                cout << "=" << val << '\n';
            else
                // put t back into c's buffer and indicate that it's full
                c.putback(t);
            val = c.expression(); // evaluate expression
        }
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


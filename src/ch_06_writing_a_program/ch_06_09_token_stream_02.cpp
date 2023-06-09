// program tests the implementation of the Calculator class, which encapsulates
// a Token_stream object to process the Tokens it receives
//
// NOTE: This program and ch_06_07_token_stream_01 are the same

// NOTE: this directive makes the Calculator class's private attributes visible
// for testing purposes
#ifndef CALC_TEST
#define CALC_TEST
#endif

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calculator_utils/calculator_utils.hpp> // for Calculator

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
        using std::cin;

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

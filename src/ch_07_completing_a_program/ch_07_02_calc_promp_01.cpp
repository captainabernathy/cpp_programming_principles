// first attempt at adding a prompt to the Calculator program
//
// Calculator (class)
//      Calculator()
//      Token get()             // typically private
//      void putback(Token t)   // typically private
//      double expression()     // typically private
//
// Token (class)
//      char kind
//      double value

// NOTE: this directive makes the Calculator class's private attributes visible
// for testing purposes and to syntax checkers
#ifndef CALC_TEST
#define CALC_TEST
#endif

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calculator_utils/calculator_utils.hpp> // for Token, Calculator

/*
 *  Grammar
 *
 *  Print:
 *      ;
 *
 *  Quit:
 *      q
 *
 *  Expression:
 *      Term
 *      Expression + Term
 *      Expression - Term
 *
 *  Term:
 *      Primary
 *      Term * Primary
 *      Term / Primary
 *
 *  Primary:
 *      Number
 *      "(" Expression ")"
 *
 *  Number:
 *      floating-point literal
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
            cout << "> "; // prompt
            Token t = c.get(); // get a token

            // evaluate token
            if (t.kind == 'q') // 'q' for quit
                break;
            if (t.kind == ';') // ';' for print
                cout << "= " << val << '\n';
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
        cerr << "Oops: unknown excpetion!\n";
        return 2;
    }

    return 0;
}

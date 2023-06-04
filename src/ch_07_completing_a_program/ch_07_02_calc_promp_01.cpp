// first attempt at adding a prompt to the Calculator program

// to make private Calculator attributes visible for testing
#ifndef CALC_TEST
#define CALC_TEST
#endif

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calc/token.hpp> // for Token
#include <calc/calculator.hpp> // for Calculator

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


// program test the implementation of the Calculator class that now includes
// support for the unary + and - in expressions

// to make private Calculator attributes visible for testing
#ifndef CALC_TEST
#define CALC_TEST
#endif

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calc/token.hpp> // for Token
#include <calc/calculator.hpp> // for Calculator
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open(),


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
 *      -Primary
 *      +Primary
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

        while (cin)
        {
            cout << "> "; // prompt
            Token t = c.get(); // get a token

            // evaluate token
            while (t.kind == ';')
                t = c.get();   // eat ';'

            if (t.kind == 'q') // 'q' for quit
            {
                keep_window_open();
                return 0;
            }
            
            // put t back into c's buffer and indicate that it's full
            c.putback(t);
            cout << "= " << c.expression() << '\n';
        }

        keep_window_open();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }

    return 0;
}


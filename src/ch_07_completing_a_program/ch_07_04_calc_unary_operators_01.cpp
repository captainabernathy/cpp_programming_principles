// program test the implementation of the Calculator class that now includes
// support for the unary + and - in expressions
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
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open()

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

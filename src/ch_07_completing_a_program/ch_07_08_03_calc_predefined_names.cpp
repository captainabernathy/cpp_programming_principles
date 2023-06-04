// program test the implementation of the Calculator class that now includes
// support for loading predefined variables into the Calculator

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <calc/calculator.hpp> // for Calculator
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open()

/*
 *  Grammar
 *
 *  Calculation:
 *      Statement
 *      Print
 *      Quit
 *      Calculation Statement
 *
 *  Statement:
 *      Declaration
 *      Expression
 *
 *  Declaration:
 *      "let" Name "=" Expression
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
 *      Term % Primary
 *
 *  Primary:
 *      Number
 *      Name
 *      ( Expression )
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
        Calculator c;
        c.define_name("pi", 3.1415926535);
        c.define_name("e", 2.7182818284);
        c.calculate();
        keep_window_open();
        return 0;
    }
    catch (exception& ex)
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
}


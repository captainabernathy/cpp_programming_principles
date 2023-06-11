// program test the implementation of the Calculator class that now includes
// a calculate() method to control the computation loop
//
// Calculator
//      Calculator()
//      void calculate()

#include <iostream> // for cerr
#include <stdexcept> // for runtime_error
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
 *      Term % Primary
 *
 *  Primary:
 *      Number
 *      ( Expression )
 *      -Primary
 *      +Primary
 *
 *  Number:
 *      floating-point literal
 */

int main()
{
    using std::cerr;
    using std::runtime_error;

    try
    {
        Calculator c;
        c.calculate();
        keep_window_open();
    }
    catch (runtime_error& ex)
    {
        cerr << ex.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception \n";
        keep_window_open("~~");
        return 2;
    }

    return 0;
}

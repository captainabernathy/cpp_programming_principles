// program test the implementation of the Calculator class that now includes
// the ability to recover from invalid input

#include <iostream> // for cerr
#include <stdexcept> // for runtime_error
#include <calc/calculator.hpp> // for Calculator
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
    using std::runtime_error;
    using std::cerr;

    try
    {
        Calculator c;
        c.calculate();
        keep_window_open();
        return 0;
    }
    catch (runtime_error& ex)
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


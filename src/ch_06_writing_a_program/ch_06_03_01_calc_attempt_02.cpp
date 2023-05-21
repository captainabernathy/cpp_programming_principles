// second attempt at writing a calculator program.
//
// program can perform addition, subtraction, multiplication, and division, but
// program cannot handle expressions that contain multiple terms (ie: 1+2+3).
// program does not perform any input validation, and program cannot handle
// operator precedence or parenthetical expressions.

#include <iostream> // for cin, cout, cerr
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;
        using std::cin;

        cout << "Please enter an expression (we can handle +, -, *, and /). "
            << "Then press 'x' when done: ";

        int lval = 0; // left operand
        int rval; // right operand

        cin >> lval; // read left operand

        if (!cin) // test cin
            error("no first operand");
        
        // read operation... and subsequently right operand
        // can perform addition, subtraction, multiplication, and division
        // can handle expressions containing multiple terms (ie: 1+2-3)
        // does not handle operator precedence or parenthetical expressions
        // does perform input validation
        for (char op; cin >> op;) // read operation
        {
            if (op != 'x') // read right operand when op is not equal to 'x'
                cin >> rval;
            if (!cin) // test cin
                error("no second operand");
            switch (op) // evaluate operation
            {
                case '+':
                    lval += rval; // add: lval = lval + rval
                    break;
                case '-':
                    lval -= rval; // subtract: lval = lval -rval
                    break;
                case '*':
                    lval *= rval; // multiply: lval = lval * rval
                    break;
                case '/':
                    lval /= rval; // divide: lval = lval / rval
                    break;
                default:
                    // write result to stdout
                    cout << "Result: " << lval << '\n';
                    keep_window_open();
                    return 0;
            }
        }

        error("bad expression"); // malformed expression
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) // catches unchecked expressions
    {
        cerr << "Oops: unknown exception!" << '\n';
        return 2;
    }

    return 0;
}

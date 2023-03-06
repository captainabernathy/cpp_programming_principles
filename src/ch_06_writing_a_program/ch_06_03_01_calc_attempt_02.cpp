#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.h" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

int main()
{
    try
    {
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
                    cout << "Result: " << lval << endl;
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
        cerr << "Oops: unknown exception!" << endl;
        return 2;
    }

    return 0;
}

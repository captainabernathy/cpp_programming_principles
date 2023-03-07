// first attempt at writing a calculator program.
//
// program can only handle expressions of the form lval +/- rval.
// program does not handle multiplication and division, and cannot handle
// complex expressions (ie:1+2+3).

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    cout << "Enter an expression (we can handle + and -): ";
    
    int lval = 0; // left operand
    
    // be wary of uninitialized variables...
    int rval;   // right operand
    char op;    // operator
    int res;    // result

    // read expression...
    // only expressions of the form lval +/- rval...
    // does not handle multiplication and division
    // does not handle complex expressions (ie: 1+2+3)
    cin >> lval >> op >> rval;

    // no input validation performed
    if (op == '+') // addition
        res = lval + rval;
    else if (op == '-') // subtraction
        res = lval - rval;

    // write result to stdout
    cout << "Result: " << res << endl;

    return 0;
}

// program demonstrates the use of pre- and post-conditions in validating
// function input and output

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.h" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

class Bad_area{}; // empty class for throwing

// function that calclates the area from its inputs and returns the result if
// inputs are greater than zero... otherwise it throws Bad_area
int area1(int length, int width);

// function that calclates the area from its inputs and returns the result if
// the inputs satisy-preconditions and output satisfies a post-condition
int area(int length, int width);

int main()
{
    try
    {
        // call will pass pre-conditions, but fail post-condition due to integer
        // overflow
        area(2000000000, 2000000000);
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!" << endl;
        return 2;
    }
}

int area1(int length, int width)
{
    // throw Bad_area if either input is not > 0
    if (length <= 0 || width <= 0)
        throw Bad_area();

    // potential integer overflow not checked
    return length * width;
}

int area(int length, int width)
{
    // pre-conditions: length and width are positive
    if (length <= 0 || width <= 0)
        error("area() pre-condition");

    int a = length * width;

    // post-condition: returns a positive value
    // checks for integer overflow
    if (a <= 0)
        error("area() post-condition");

    return a;
}


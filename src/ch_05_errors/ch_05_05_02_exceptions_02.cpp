// program demonstrates error checking where it is the responsiblitiy of the
// function being called to validate its inputs

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing helper functions

// function that calclates the area from its inputs and returns the result if
// inputs are greater than zero... otherwise it calls error()
int area(int len, int width);

// another function that will perfom a computation using its inputs only if
// they are valid... otherwise it calls errror()
int framed_area(int x, int y);

int main()
{
    using std::exception;
    using std::cerr;

    try // calls to area() and framed_area() may throw
    {
        using std::cout;

        int x = -1;
        int y = 2;
        int z = 4;

        int area1 = area(x, y); // function validates input
        cout << area1 << '\n';

        int area2 = framed_area(1, z); // function validates input
        cout << area2 << '\n';

        int area3 = framed_area(y, z); // function validates input
        cout << area3 << '\n';

        // potential division by zero w/o check
        double ratio = double(area1) / area3;
        cout << ratio << '\n';
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!" << '\n';
        return 2;
    }

    return 0;
}

int area(int len, int width)
{
    // NOTE: error() throws a runtime exception when called
    if (len <= 0 || width <= 0)
        error("non-positive argument in call to area()");
    // computation performed only after inputs have been validated
    // potential integer overflow not checked
    return len * width;
}

int framed_area(int x, int y)
{
    // implementation detail not maintained internally by function
    constexpr int frame_width = 2;
    if (x - frame_width <= 0 || y - frame_width <= 0)
        error("non-positive argument in call to area() called by "
                "framed_area()");
    // return result only after inputs have been verified
    return area(x - frame_width, y - frame_width);
}

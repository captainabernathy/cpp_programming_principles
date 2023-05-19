// program demonstrates error checking where it is the caller's responsiblitiy
// to validate the inputs to a function

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <cpp_facilities/std_lib_facilities.hpp> // project helper functions

// simple function that calculates area from its inputs and returns the result
inline int area(int len, int width)
{
    // potential integer overflow not checked
    return len * width;
}

constexpr int frame_width = 2; // magic number... not the best idea

// function wraps a call for area... results depend on frame_width... which
// makes it brittle
inline int framed_area(int x, int y)
{
    return area(x - frame_width, y - frame_width);
}

int main()
{
    using std::exception;
    using std::cerr;

    int x = -1;
    int y = 2;
    int z = 4;

    // NOTE: error() function is provided by std_lib_facilities.h and catches
    // runtime errors
    try // code that may call error()
    {
        using std::cout;

        {
            // call error if either x or y is not positive
            if (x <= 0)
                error("non-positive x");
            if (y <= 0)
                error("non-positive y");

            int area1 = area(x, y); // computed only if inputs are valid
            cout << area1 << '\n';
        }
        {
            if (x <= 0 || y <= 0) // more compact check for invalid x or y values
                error("non-positive argument in call to area()");

            int area1 = area(x, y);  // computed only if inputs are valid

            // nonsensical result bc input to framed area should be >= 2
            int area2 = framed_area(1, z);
            cout << area2 << '\n'; // no error checking lead to invalid result

            // inputs to framed area should be > 2
            if (y <= 2 || z <= 2)
                error("non-positive argument in call to area() called by "
                    "framed_area()");

            int area3 = framed_area(y, z); // computed only if inputs are valid
            cout << area3 << '\n';

            // potential division by zero w/o check
            double ratio = double(area1) / area3; // convert to double
            cout << ratio << '\n';
        }
        {
            //  tests exposes implementation detail of framed_area(), which is
            //  undesirable
            if (1 - frame_width <= 0 || z - frame_width <= 0)
                error("non-positive 2nd argument in call to area() called "
                        "by framed_area()");

            int area2 = framed_area(1, z); // computed only if inputs are valid
            cout << area2 << '\n';

            // another brittle test that depends on evaluation against a magic
            // constant
            if (y - frame_width <= 0 || z - frame_width <= 0)
                error("non-positive 2nd argument in called to area called "
                        "by framed_area()");

            int area3 = framed_area(y, z); // computed only if inputs are valid
            cout << area3 << '\n';
        }
    }
    catch (exception& e) // catches exceptions from error()
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) // catches unexpected exceptions
    {
        cerr << "Oops: unknown exception!" << '\n';
        return 2;
    }

    return 0;
}

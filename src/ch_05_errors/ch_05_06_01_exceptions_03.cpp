// program demonstrates how to throw, try, and catch a unique exception type to
// indicate a specific error

#include <iostream> // for cerr, cout
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

class Bad_area{}; // empty class for throwing

// function that calclates the area from its inputs and returns the result if
// inputs are greater than zero... otherwise it throws Bad_area
int area(int len, int width);

// another function that will perfom a computation using its inputs only if
// they are valid... otherwise it calls errror()
int framed_area(int x, int y);

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;

        int x = -1;
        int y = 2;
        int z = 4;

        int area1 = area(x, y); // throws Bad_area if inputs are invalid
        cout << area1 << '\n';

        int area2 = framed_area(1, z); // function validates input
        cout << area2 << '\n';

        int area3 = framed_area(y, z); // function validates input
        cout << area3 << '\n';

        // potential division by zero w/o check
        double ratio = double(area1) / area3;
        cout << ratio << '\n';
    }
    catch (Bad_area) // catches Bad_area
    {
        cerr << "Oops! bad arguments to area()\n";
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}

int area(int len, int width)
{
    // throw Bad_area if either input is not > 0
    if (len <= 0 || width <= 0)
        throw Bad_area();
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

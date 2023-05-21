// program creates an empty window

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top left

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas"};
        win.wait_for_button(); // give control to display engine
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "undefined exception" << '\n';
        return 2;
    }

    return 0;
}

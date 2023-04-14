// program creates an empty window

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors

int main()
{
    using namespace Graph_lib;
    using std::cerr;
    using std::endl;
    using std::exception;

    try
    {
        Point top_left(100, 100); // top left

        // build a window
        Simple_window win(top_left, 600, 400, "Canvas");
        win.wait_for_button(); // give control to display engine
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "undefined exception" << endl;
        return 2;
    }

    return 0;
}

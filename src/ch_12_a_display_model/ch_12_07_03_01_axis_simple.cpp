// program creates a window that contains a horizontal axis

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
        Point top_left {100, 100}; // top-left corner

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas"};

        
        // Axis is a shape
        // Axis::x means horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "x axis"
        Axis xa {Axis::x, {20, 300}, 280, 10, "x axis"};
        // xa.label.set_font_size(10);

        win.attach(xa); // attach Axis to window

        win.set_label("Canvas #2"); // relabel window

        win.wait_for_button(); // give control to display manager
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception" << endl;
        return 2;
    }

    return 0;
}

// program demonstrates how to draw a Shape using the graphics library's
// Closed_polyline class

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors

int main()
{
    using std::cerr;
    using std::endl;
    using std::exception;

    try
    {
        using namespace Graph_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Closed polyline"};

        // NOTE: a Closed_polyline is similar to an Open_polyline except that
        // we also draw a line from the last Point to the first
        // Closed_polyline cpl;
        // cpl.add({100, 100});
        // cpl.add({150, 200});
        // cpl.add({250, 250});
        // cpl.add({300, 200});

        Closed_polyline cpl {{100, 100}, {150, 200}, {250, 250}, {300, 200}};

        win.attach(cpl); // attach to window
        win.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}

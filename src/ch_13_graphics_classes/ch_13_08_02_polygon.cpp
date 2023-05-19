// program demonstrates how to use the Polygon class to draw a polygon in a
// Simple_window

#include <GUI/Simple_window.hpp> // provides access to our simple window library
#include <GUI/Graph.hpp> // provides access to our graphics library
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
        Simple_window win {{100, 100}, 600, 400, "Polygon"};

        // NOTE: a Polygon is a Shape that is enclosed by a series of
        // non-intersecting line segments defined by a series of Points
        // Polygon poly;
        // poly.add({100, 100});
        // poly.add({150, 200});
        // poly.add({250, 250});
        // poly.add({300, 200});

        Polygon poly {{100, 100}, {150, 200}, {250, 250}, {300, 200}};

        win.attach(poly); // attach to window
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

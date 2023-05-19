// program demonstrates how to use the graphics library's Marks class

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
        Simple_window win {{100, 100}, 600, 400, "Marks"};

        // a Marks object is similar to a Marked_polyline, except the line
        // is invisible
        // Marks mk {"x"};
        // mk.add({100, 100});
        // mk.add({150, 200});
        // mk.add({250, 250});
        // mk.add({300, 200});

        // Marks object with four points
        Marks mk {"x", {{100, 100}, {150, 200}, {250, 250}, {300, 200}}};

        win.attach(mk); // attach Marks object
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

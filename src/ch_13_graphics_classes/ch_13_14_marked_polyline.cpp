// program demonstrates how to use the graphics library's Marked_polyline
// class

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
        Simple_window win {{100, 100}, 600, 400, "Marked polyline"};

        // create a Marked_polyline with 4 marks
        Marked_polyline mpl {"1234"};

        // add 4 points to mpl... one for each mark
        mpl.add({100, 100});
        mpl.add({150, 200});
        mpl.add({250, 250});
        mpl.add({300, 200});

        win.attach(mpl); // attach Marked_polyline
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

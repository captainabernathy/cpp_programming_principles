// program demonstrates how a Closed_polyline object might produce an
// ill-formed polygon

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // Point, Closed_polyline

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Closed polyline"};

        // NOTE: a Closed_polyline is similar to an Open_polyline except that
        // we also draw a line from the last Point to the first
        // Closed_polyline cpl;
        // cpl.add({100, 100});
        // cpl.add({150, 200});
        // cpl.add({250, 250});
        // cpl.add({300, 200});
        // cpl.add({100, 250}); // leads to an ill-formed polygon

        Closed_polyline cpl {{100, 100}, {150, 200}, {250, 250}, {300, 200},
                             {100, 250}};
        win.attach(cpl); // attach to window
        win.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << '\n';
        return 2;
    }

    return 0;
}

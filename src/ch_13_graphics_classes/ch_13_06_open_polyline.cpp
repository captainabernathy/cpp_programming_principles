// program demonstrates how to draw a Shape using the graphics library's
// Open_polyline class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Open_polyline

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Open polyline"};

        // NOTE: an Open_polyline is a Shape that is composed of a series of
        // connected line segments defined by a series of Points
        // Open_polyline opl;
        // opl.add({100, 100});
        // opl.add({150, 200});
        // opl.add({250, 250});
        // opl.add({300, 200});

        Open_polyline opl {{100, 100}, {150, 200}, {250, 250}, {300, 200}};

        win.attach(opl); // attach to window
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

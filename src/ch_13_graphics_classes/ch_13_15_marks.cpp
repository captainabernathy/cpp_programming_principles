// program demonstrates how to use the graphics library's Marks class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Marks

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

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
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

// program demonstrates how to use the graphics library's Text class to create,
// manipulate, and display a text in a Simple_window

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Closed_polyline, Text, Color

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Closed polyline with text"};

        // Closed_polyline cpl;
        // cpl.add({100, 100});
        // cpl.add({150, 200});
        // cpl.add({250, 250});
        // cpl.add({300, 200});
        // cpl.add({100, 250}); // creates an ill-formed polygon

        Closed_polyline cpl {{100, 100}, {150, 200}, {250, 250}, {300, 200},
                             {100, 250}};

        win.attach(cpl); // attach Closed_polyline to win

        // create a Text object that extends from a line with a lower left
        // coordinate of (200, 200)
        Text t {{200, 200}, "A closed polyline that isn't a polygon"};

        // change Text object's color
        t.set_color(Color::blue);

        // change Text object's Font size
        t.set_font_size(20);

        win.attach(t); // attach Text object to win

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

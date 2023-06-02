// program demonstrates how to use the graphics library's Ellipse class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> //  for Point, Ellipse

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Ellipses"};

        // for Ellipses... pass a center point and x and y distances from it
        // Ellipse with a center at (200, 200) bound by points +/- 50 pixels
        // in the horizontal and vertical directions
        Ellipse e1 {{200, 200}, 50, 50};

        // Ellipse with a center at (200, 200) bound by points +/- 100 pixels
        // away in the horizontal direction and +/- 50 pixels away in the
        // vertical direction
        Ellipse e2 {{200, 200}, 100, 50};

        // Ellipse with a center at (200, 200) bound by points +/- 100 pixels
        // away in the horizontal direction and +/- 150 pixels away in the
        // vertical direction
        Ellipse e3 {{200, 200}, 100, 150};

        // attach Ellipses to win
        win.attach(e1);
        win.attach(e2);
        win.attach(e3);

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

// program demonstrates how to use the graphics library's Mark class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Circle, Mark, Color

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Circles with ceners"};

        // three Circle objects
        Circle c1 {{100, 200}, 50};
        Circle c2 {{150, 200}, 100};
        Circle c3 {{200, 200}, 150};

        // attach Circles to win
        win.attach(c1);
        win.attach(c2);
        win.attach(c3);

        // a Mark object represents a character to be displayed at a Point
        Mark m1 {{100, 200}, 'x'};
        Mark m2 {{150, 200}, 'y'};
        Mark m3 {{200, 200}, 'z'};

        // set the color of each Circle
        c1.set_color(Color::blue);
        c2.set_color(Color::red);
        c3.set_color(Color::green);

        // attach each Mark to win
        win.attach(m1);
        win.attach(m2);
        win.attach(m3);

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

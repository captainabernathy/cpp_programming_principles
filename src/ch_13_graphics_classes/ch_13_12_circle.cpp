// program demonstrates how to use the graphics library's Circle class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Cirlce

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Circles"};

        // Circle with center (100,200) and raidus 50
        Circle c1 {{100, 200}, 50};

        // Circle with center (150,200) and radius 100
        Circle c2 {{150, 200}, 100};

        // Circle with center (200, 200) and radius 150
        Circle c3 {{200, 200}, 150};

        // attach Circles to win
        win.attach(c1);
        win.attach(c2);
        win.attach(c3);

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

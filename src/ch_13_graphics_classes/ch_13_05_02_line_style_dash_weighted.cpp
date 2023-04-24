// program uses a Lines object to display a red grid of dashed lines in a
// Simple_window

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
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
        Simple_window win3 {{100, 100}, 600, 400, "grid"};

        // get window size
        int x_size = win3.x_max(); // window width
        int y_size = win3.y_max(); // window height
        int x_grid = 80; // x offset
        int y_grid = 40; // y offset

        Lines grid; // start empty

        // add vertical lines in incrememts of 80 pixels to the grid
        for (int x = x_grid; x < x_size; x += x_grid)
            grid.add({x, 0}, {x, y_size}); // vertical line

        // add horizontal lines in increments of 40 pixels to the grid
        for (int y = y_grid; y < y_size; y += y_grid)
            grid.add({0, y}, {x_size, y}); // horizontal line

        grid.set_color(Color::red); // make Lines red

        // make Lines dashed and 2 pixels wide
        grid.set_style({Line_style::dash, 2}); // thick dashes

        win3.attach(grid); // attach lines to window
        win3.wait_for_button(); // display
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

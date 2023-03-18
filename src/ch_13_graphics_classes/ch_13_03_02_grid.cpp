#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        using namespace Graph_lib;

        Simple_window win3(Point(100, 100), 600, 400, "grid");

        // get window size
        int x_size = win3.x_max();
        int y_size = win3.y_max();
        int x_grid = 80;
        int y_grid = 40;

        Lines grid;
        for (int x = x_grid; x < x_size; x += x_grid)
            grid.add(Point(x, 0), Point(x, y_size)); // vertical line

        for (int y = y_grid; y < y_size; y += y_grid)
            grid.add(Point(0, y), Point(x_size, y)); // horizontal line

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

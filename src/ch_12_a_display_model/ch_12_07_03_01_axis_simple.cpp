#include <iostream>
#include <stdexcept>
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;
using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        Point top_left(100, 100); // top-left corner

        Simple_window win(top_left, 600, 400, "Canvas");

        /*
         * Axis is a shape
         * Axis::x means horizontal
         * starting at (20, 300)
         * 280 pixels long
         * 10 notches
         * labeled "x axis"
         */
        Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
        // xa.label.set_font_size(10);

        win.attach(xa); // attach axis to window
        win.set_label("Canvas #2"); // relabel window
        win.wait_for_button(); // give control to display manager
    }
    catch(exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown exception" << endl;
        return 2;
    }

    return 0;
}

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
        Point top_left(100, 100); // top left corner

        Simple_window win(top_left, 600, 400, "Canvas");

        /*
         * Axis is a Shape
         * Axis::x = horizontal
         * starting at (20, 300)
         * 280 pixels long
         * 10 notches
         * labeled "x axis"
         */
        Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
        win.attach(xa);

        Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
        ya.set_color(Color::cyan); // set color
        ya.label.set_color(Color::dark_red); // set text color
        win.attach(ya);

        /*
         * plot sin() in range of [0:100) with (0, 0) at (20, 150)
         * using 1000 points
         * scale x values * 50
         * scale y values * 50
         */
        Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);
        win.attach(sine);

        win.set_label("Canvas #4");
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

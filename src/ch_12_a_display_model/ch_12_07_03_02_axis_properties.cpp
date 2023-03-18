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
        ya.label.set_color(Color::dark_red); // text color
        win.attach(ya);
        win.set_label("Canvas #3"); // relabel window
        win.wait_for_button(); // give control to display manager
    }
    catch(exception &ex)
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

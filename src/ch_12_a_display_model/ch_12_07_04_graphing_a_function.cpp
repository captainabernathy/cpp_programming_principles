// program creates a window that contains a horizontal and vertical axis and
// demonstrates how to plot a function

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors

int main()
{
    using namespace Graph_lib;
    using std::cerr;
    using std::endl;
    using std::exception;

    try
    {
        Point top_left(100, 100); // top left corner

        // build a window
        Simple_window win(top_left, 600, 400, "Canvas");
        
        // Axis is a Shape
        // Axis::x = horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "x axis"
        Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");

        // attach Axis to window
        win.attach(xa);

        
        // Axis is a Shape
        // Axis::y = vertical
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "y axis"
        Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");

        // set y Axis color to cyan
        ya.set_color(Color(Color::cyan));

        // set y Axis label color to dark_red
        ya.label.set_color(Color(Color::dark_red));

        // attach y Axis to window
        win.attach(ya);

        
        // plot sin() in range of [0:100) with (0,0) at (20,150)
        // using 1000 points
        // scale x values * 50
        // scale y values * 50
        Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);

        // attach Function to window
        win.attach(sine);

        // change window title
        win.set_label("Canvas #4");
        win.wait_for_button(); // give control to display manager
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception" << endl;
        return 2;
    }

    return 0;
}

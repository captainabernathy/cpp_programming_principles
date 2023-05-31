// program creates a window that contains a horizontal and vertical axis and
// demonstrates how to manipulate axis properties

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Axis, Color

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top-left corner

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas #3"};
        
        // Axis is a Shape
        // Axis::x = horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "x axis"
        Axis xa {Axis::x, {20, 300}, 280, 10, "x axis"};

        // Attach Axis to window
        win.attach(xa);

        
        // Axis is a Shape
        // Axis::y = vertical
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "y axis"
        
        // build another Axis
        Axis ya {Axis::y, {20, 300}, 280, 10, "y axis"};

        // set y Axis color to cyan
        ya.set_color(Color::cyan);
        
        // set y Axis label color to dark_red
        ya.label.set_color(Color::dark_red);

        // attach y Axis to window
        win.attach(ya);

        // change window title
        win.set_label("Canvas #3");

        win.wait_for_button(); // give control to display manager
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception" << '\n';
        return 2;
    }

    return 0;
}

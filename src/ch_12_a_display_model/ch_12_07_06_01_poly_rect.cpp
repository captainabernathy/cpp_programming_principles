// program continues to demonstrate how to use the features of the graphics
// library by showing how to build a rectangle with a Closed_polyline object

#include <iostream> // for cerr
#include <exception> // for exception
#include <cmath> // for sin()
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Axis, Color, Function, Polygon,
                            // Line_style, Rectangle, Closed_polyline

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top left

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas #6.1"};

        // build a 280 pixel long horizontal Axis starting at (20,300) with
        // 10 notches labeled "x axis"
        Axis xa {Axis::x, {20, 300}, 280, 10, "x axis"};

        // attach x Axis to window
        win.attach(xa);

        // build a 280 pixel long vertical Axis starting at (20,300) with 10
        // notches labeled "y axis"
        Axis ya {Axis::y, {20, 300}, 280, 10, "y axis"};

        // set y Axis color to cyan
        ya.set_color(Color::cyan);

        // set y Axis label color to dark_red
        ya.label.set_color(Color::dark_red);

        // attach y Axis to window
        win.attach(ya);

        // plot sin() in range [0:100) with (0,0) at (20,150) using 1000 points
        // and scale x and y values * 50
        Function sine {sin, 0, 100, {20, 150}, 1000, 50, 50};

        // attach Function to window
        win.attach(sine);

        // change Function's color to blue
        sine.set_color(Color::blue);

        // construct a triangle with the Polygon
        // Polygon poly;
        // poly.add({300, 200}); // lower left
        // poly.add({350, 100}); // peak
        // poly.add({400, 200}); // lower right

        Polygon poly {{300, 200}, {350, 100}, {400, 200}};

        // set the Polygon's color to red
        poly.set_color(Color::red);

        // set the Polgon's Line_style to dashed
        poly.set_style(Line_style::dash);

        // attach the Polygon to the window
        win.attach(poly);

        // build a Rectangle with it's upper left corner at (200,200) and
        // a width of 100 and height of 50
        Rectangle r {{200, 200}, 100, 50}; // top left, width, height

        // attach Rectangle to window
        win.attach(r);

        // build a Rectangle from a Closed_polyline
        // Closed_polyline poly_rect;
        // poly_rect.add({100, 50}); // top left corner at (100,50)
        // poly_rect.add({200, 50}); // top right corner at (200,50)
        // poly_rect.add({200, 100}); // lower right at (200,100)
        // poly_rect.add({100, 100}); // lower left at (100,100)

        Closed_polyline poly_rect {{100, 50}, {200, 50}, {200, 100},
                                   {100, 100}};

        // attach Closed_polyline to window
        win.attach(poly_rect);

        // change window title
        win.set_label("Canvas #6.1");
        win.wait_for_button(); // give control to display manager
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception\n";
        return 2;
    }

    return 0;
}

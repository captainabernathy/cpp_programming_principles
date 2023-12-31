// program continues to demonstrate how to use the features of the graphics
// library by showing how to insert an Image into a window

#include <iostream> // for cerr
#include <exception> // for exception
#include <cmath> // for sin()
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Axis, Color, Function, Polygon,
                            // Line_style, Rectangle, Closed_polyline, Text,
                            // Font, Image

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top left corner

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas #10"};

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

        // plot sin() in range [0:100) with (0,0) at (20,150) using 1000 points,
        // and scale and x and v values * 50
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

        // change the Polygon's Line_style to dashed with a width of 4
        poly.set_style({Line_style::dash, 4});

        // build a Rectangle with it's upper left corner at (200,200) and
        // a width of 100 and height of 50
        Rectangle r {{200, 200}, 100, 50}; // top left, width, height

        // attach Rectangle to window
        win.attach(r);

        // set the Rectangle's fill color to yellow
        r.set_fill_color(Color::yellow);

        // build a complex polygon with a Closed_polyline
        // Closed_polyline complex_poly;
        // complex_poly.add({100, 50}); // top left
        // complex_poly.add({200, 50}); // top right
        // complex_poly.add({200, 100}); // lower right
        // complex_poly.add({100, 100}); // lower left

        Closed_polyline complex_poly {{100, 50}, {200, 50}, {200, 100},
                                      {100, 100}};

        // left facing point between upper and lower left corners
        complex_poly.add({50, 75});

        // attach complex polygon to window
        win.attach(complex_poly);

        // set the Closed_polyline's Line_sytle to dashed with a width of 2
        complex_poly.set_style({Line_style::dash, 2});

        // set the Closed_polyline's fill color to green
        complex_poly.set_fill_color(Color::green);

        // build a Text object with its lower left corner at (150,150)
        Text t {{150, 150}, "Hello, graphical world!"};

        // attach Text object to window
        win.attach(t);

        // set Text object's font to times_bold
        t.set_font(Graphics_lib::Font::times_bold);

        // set Text object's font size to 20
        t.set_font_size(20);

        // build an Image object with its upper left corner at (100,50)
        Image ii {{100, 50}, "image.jpg"}; // 400 * 212 pixel jpg

        // attach Image to window
        win.attach(ii);

        // change window title
        win.set_label("Canvas #10");
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

// program continues to demonstrate how to use the features of the graphics
// library by decorating an Image with Circle, Ellipse, Mark, and Text objects

#include <iostream> // for cerr
#include <sstream> // string stream library header
#include <cmath> // for sin()
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Axis, Color, Function, Polygon,
                            // Line_style, Rectangle, Closed_polyline,
                            // Text, Font, Image, Circle, Ellipse, Mark,

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::ostringstream;
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top left corner

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas #12"};

        // build a 280 pixel long horizontal Axis starting at (20,300) with
        // 10 notches labeled "x axis"
        Axis xa {Axis::x, {20, 300}, 280, 10, "x axis"};

        // attach x Axis to window
        win.attach(xa);

        // build a 280 pixel long vertical Axis starting at (20,300) with 10
        // notches labeled "y axis"
        Axis ya {Axis::y, {20, 300}, 280, 10, "y axis"};

        // set y Axis color to cyan
        ya.set_color(Color::cyan); // set color

        // set y Axis label color to dark_red
        ya.label.set_color(Color::dark_red); // text color

        // attach y Axis to window
        win.attach(ya);

        // plot sin() in range [0:100) with (0,0) at (20,150) using 1000 points,
        // and scale x and y values * 50
        Function sine {sin, 0, 100, {20, 150}, 1000, 50, 50};

        // attach Function to window
        win.attach(sine);

        // change Function's color to blue
        sine.set_color(Color::blue); // change color

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
        // complex_poly.add({100, 50}); // upper left
        // complex_poly.add({200, 50}); // upper right
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
        Image ii {{100, 50}, "image.jpg"}; // 400 * 212

        // attach Image to window
        win.attach(ii);

        // move Image 100 pixels to the right and 200 pixels down
        ii.move(100, 200);

        // build a Circle with a center at (100,200) with a raidus of 50
        Circle c {{100, 200}, 50};

        // build an Ellipse with a center at (100,200) with a distance of 75
        // from the center on the x axis and 25 from center on the y axis
        Ellipse e {{100, 200}, 75, 25};

        // set Ellipse's color to dark_red
        e.set_color(Color::dark_red);

        // build a Mark at (100,200) with the symbol x
        Mark m {{100, 200}, 'x'};

        ostringstream oss;
        // build up an output string
        oss << "screen size: " << x_max() << "*" << y_max() << "; window size: "
            << win.x_max() << "*" << win.y_max();

        // build a Text object with its lower left corner at (100,20) that
        // contains the output string
        Text sizes {{100, 20}, oss.str()};

        // build an Image object with its upper left corner at (225,225)
        Image cal {{225, 225}, "snow_cpp.gif"}; // 320 * 240 gif

        // select a 200 by 150 pixel sub image of cal at a point 40 pixels
        // right and 40 pixels down from its upper left corner
        cal.set_mask({40, 40}, 200, 150);

        // attach Circle to window
        win.attach(c);

        // attach Mark to image
        win.attach(m);

        // attach Ellipse to window
        win.attach(e);

        // attach Text object to window
        win.attach(sizes);

        // attach Image to window
        win.attach(cal);

        // change window title
        win.set_label("Canvas #12");
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

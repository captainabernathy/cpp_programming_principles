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

        // 280 pixel long horizontal axis starting at (20,300) with 10 notches
        // and the label "x axis"
        Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
        win.attach(xa);

        Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
        ya.set_color(Color::cyan); // set color
        ya.label.set_color(Color::dark_red); // text color
        win.attach(ya);

        // plot sin() in range [0:100) with (0,0) at (20,150) using 1000 points,
        // and scale x and y values * 50
        Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);
        win.attach(sine);
        sine.set_color(Color::blue); // change color

        Polygon poly;
        poly.add(Point(300, 200)); // lower left
        poly.add(Point(350, 100)); // peak
        poly.add(Point(400, 200)); // lower right
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);

        Rectangle r(Point(200, 200), 100, 50); // top left, width, height
        win.attach(r);

        Closed_polyline poly_rect;
        poly_rect.add(Point(100, 50)); // top left
        poly_rect.add(Point(200, 50)); // top right
        poly_rect.add(Point(200, 100)); // lower left
        poly_rect.add(Point(100, 100)); // lower right
        poly_rect.add(Point(50, 75)); // point between lower and upper left
        win.attach(poly_rect);

        r.set_fill_color(Color::yellow); // fill rectangle
        poly.set_style(Line_style(Line_style::dash, 4)); // triangle lines
        poly_rect.set_style(Line_style(Line_style::dash, 2)); // carton lines
        poly_rect.set_fill_color(Color::green); // carton colors

        Text t(Point(150, 150), "Hello, graphical world!");
        win.attach(t);
        t.set_font(Graph_lib::Font::times_bold);
        t.set_font_size(20);

        win.set_label("Canvas #9");
        win.wait_for_button();
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
// program creates a window and draws a triangle in it

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library

int main()
{
    using namespace Graph_lib; // easy access to Graph_lib

    Point top_left(100, 100); // top left corner of window

    Simple_window win(top_left, 600, 400, "Canvas"); // make simple window

    Polygon poly; // shape

    poly.add(Point(300, 200)); // lower left of triangle
    poly.add(Point(350, 100)); // top of triangle
    poly.add(Point(400, 200)); // lower right of triangle

    poly.set_color(Color(Color::red)); // adjust Polygon' properties

    win.attach(poly); // connect Polygon to window
    win.wait_for_button(); // give control to display engine

    return 0;
}

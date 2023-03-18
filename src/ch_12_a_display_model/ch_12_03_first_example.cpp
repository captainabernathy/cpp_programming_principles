#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib; // easy access to Graph_lib

    Point top_left(100, 100); // top left corner of window

    Simple_window win(top_left, 600, 400, "Canvas"); // make simple window

    Polygon poly; // shape

    poly.add(Point(300, 200)); // lower left of triangle
    poly.add(Point(350, 100)); // top of triangle
    poly.add(Point(400, 200)); // lower right of triangle

    poly.set_color(Color::red); // adjust polygon properties

    win.attach(poly); // connect poly to window
    win.wait_for_button(); // give control to display engine

    return 0;
}

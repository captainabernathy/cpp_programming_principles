// program creates a window and draws a triangle in it

#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Polygon, Color

int main()
{
    using namespace Graphics_lib; // easy access to Graphics_lib

    Point top_left {100, 100}; // top left corner of window

    Simple_window win {top_left, 600, 400, "Canvas"}; // make simple window

    Polygon poly; // shape

    poly.add({300, 200}); // lower left of triangle
    poly.add({350, 100}); // top of triangle
    poly.add({400, 200}); // lower right of triangle

    poly.set_color(Color::red); // adjust Polygon' properties

    win.attach(poly); // connect Polygon to window
    win.wait_for_button(); // give control to display engine

    return 0;
}

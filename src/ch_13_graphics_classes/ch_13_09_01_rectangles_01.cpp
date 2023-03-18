#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        using namespace Graph_lib;

        Simple_window win(Point(100, 100), 600, 400, "Rectangle");

        Rectangle r0(Point(150, 100), 200, 100);
        Rectangle r1(Point(50, 50), Point(250, 150));
        Rectangle r2(Point(50, 150), Point(250, 250)); // below r1
        Rectangle r3(Point(250, 50), 200, 100); // right of r1
        Rectangle r4(Point(250, 150), 200, 100); // below r3

        r0.set_fill_color(Color::yellow);
        r1.set_fill_color(Color::blue);
        r2.set_fill_color(Color::red);
        r3.set_fill_color(Color::green);

        win.attach(r0);
        win.attach(r1);
        win.attach(r2);
        win.attach(r3);
        // win.attach(r4);

        win.set_label("rectangles");
        win.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}

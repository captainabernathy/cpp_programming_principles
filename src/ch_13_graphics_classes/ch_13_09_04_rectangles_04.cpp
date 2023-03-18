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
        Rectangle r3(Point(250, 50), 200, 100); // to the right of r1
        Rectangle r4(Point(250, 150), 200, 100); // below r3

        r0.set_fill_color(Color::yellow);
        r1.set_fill_color(Color::blue);
        r2.set_fill_color(Color::red);
        r3.set_fill_color(Color::green);

        r1.move(400, 0); // to the right of r3
        r1.set_fill_color(Color::white); // change fill color

        win.attach(r0);
        win.attach(r1);
        win.attach(r2);
        win.attach(r3);
        // win.attach(r4);

        win.put_on_top(r0); // put r0 on top

        // make borders invisible
        r0.set_color(Color::invisible);
        r1.set_color(Color::invisible);
        r2.set_color(Color::invisible);
        r3.set_color(Color::invisible);
        r4.set_color(Color::invisible);

        win.set_label("rectangles 4");
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

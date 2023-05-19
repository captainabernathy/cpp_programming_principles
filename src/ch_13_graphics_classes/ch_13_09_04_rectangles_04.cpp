// program demonstrates how to use the Rectangle class to draw and manipulate
// rectangles in a Simple_window

#include <GUI/Simple_window.hpp> // provides access to our simple window library
#include <GUI/Graph.hpp> // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors

int main()
{
    using std::cerr;
    using std::endl;
    using std::exception;

    try
    {
        using namespace Graph_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Rectangle"};

        // build a 200 by 100 pixel Rectangle with its upper left corner at
        // (150, 100)
        Rectangle r0 {{150, 100}, 200, 100};

        // build a Rectangle with an upper left corner at (50, 50) and a lower
        // right corner at (250, 150)
        Rectangle r1 {{50, 50}, {250, 150}};
    
        // build a Rectangle with an upper left corner at (50, 150) and a lower
        // right corner at (250, 250)
        Rectangle r2 {{50, 150}, {250, 250}}; // below r1

        // build a 200 by 100 pixel Rectangle with its upper left corner at
        // (250,50)
        Rectangle r3 {{250, 50}, 200, 100}; // to the right of r1

        // build a 200 by 100 pixel Rectangle with its upper left corner at
        // (250,150)
        Rectangle r4 {{250, 150}, 200, 100}; // below r3

        // set Rectangles fill colors
        r0.set_fill_color(Color::yellow);
        r1.set_fill_color(Color::blue);
        r2.set_fill_color(Color::red);
        r3.set_fill_color(Color::green);

        // move and change the colore of Rectangle r1
        r1.move(400, 0); // to the right of r3
        r1.set_fill_color(Color::white); // change fill color

        // attach Rectangles to window
        win.attach(r0);
        win.attach(r1);
        win.attach(r2);
        win.attach(r3);
        win.attach(r4);

        // put Rectangle r0 on top of the objects in win
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

// program creates a window that contains a horizontal axis

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Axis

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        Point top_left {100, 100}; // top-left corner

        // build a window
        Simple_window win {top_left, 600, 400, "Canvas #2"};

        
        // Axis is a shape
        // Axis::x means horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 notches
        // labeled "x axis"
        Axis xa {Axis::x, {20, 300}, 280, 10, "x axis"};
        // xa.label.set_font_size(10);

        win.attach(xa); // attach Axis to window

        win.set_label("Canvas #2"); // relabel window

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

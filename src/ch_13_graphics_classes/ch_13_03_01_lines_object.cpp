// program demonstrates how to use the graphics library's Lines class

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Lines

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win1 {{100, 100}, 600, 400, "lines: +"};

        
        // Lines x; // a Lines object is a collection of lines

        // add a Line that extends from (100, 100) to (200, 100) to x
        // x.add({100, 100}, {200, 100}); // first line (horizontal)

        // add a Line that extends from (150, 50) to (150, 150)
        // x.add({150, 50}, {150, 150}); // second line (vertical)

        Lines x {{{100, 100}, {200, 100}}, {{150, 50}, {150, 150}}};
        win1.attach(x); // attach lines to window
        win1.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << '\n';
        return 2;
    }

    return 0;
}

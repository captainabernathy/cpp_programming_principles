// program demonstrates how to use the graphics library's Point and Line
// classes

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // provides access to our graphics library

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win1 {{100, 100}, 600, 400, "two lines"};

        // create a Line that extends from (100, 100) to (200, 100)
        Line horizontal {{100, 100}, {200, 100}}; // horizontal line

        // create a Line that extends from (150, 50) to (150, 150)
        Line vertical {{150, 50}, {150, 150}}; // vertical line

        // attach Lines to window
        win1.attach(horizontal);
        win1.attach(vertical);

        win1.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "undefined exception\n";
        return 2;
    }

    return 0;
}

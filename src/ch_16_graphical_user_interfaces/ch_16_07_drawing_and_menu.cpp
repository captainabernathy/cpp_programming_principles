// program allows a user to display a sequence of lines as specified by a
// sequence of coordinate pairs and also allows the user to change the color
// of the line
//
// program tests the implementation of the Lines_window class, which uses the
// graphics library to create a Window type specific to program features

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Window.hpp> // for gui_main()
#include "lines_window.hpp" // for Lines_window

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        // initialize a Lines_window
        Lines_window win {{100, 100}, 600, 400, "lines"};
        Graphics_lib::gui_main(); // run the program
    }
    catch (exception& ex)
    {
        cerr << "exception" << ex.what() << '\n';
        return 1;
    }
    catch ( ... )
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

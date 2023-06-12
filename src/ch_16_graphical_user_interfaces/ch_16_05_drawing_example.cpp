// program allows a user to display a sequence of lines as specified by a
// sequence of coordinate pairs
//
// program demonstrates how to use the graphics library to create a Window
// specific to program features

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Window.hpp> // for gui_main()
#include "lines_window.hpp" // for Lines_window

int main(void)
{
    using std::exception;
    using std::cerr;

    try
    {
        Lines_window win {{100, 100}, 600, 400, "lines"};
        Graphics_lib::gui_main();
    }
    catch (exception& ex)
    {
        cerr << "exception: " << ex.what() << '\n';
        return 1;
    }
    catch ( ... )
    {
        cerr << "Unknown exception\n";
        return 2;
    }

    return 0;
}

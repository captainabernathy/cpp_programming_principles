// program demonstrates how to use the graphics library's Image class to
// create, display, and manipulate images in a Simple_window

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Image

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // create a 600 by 400 window with an upper left corner at (100, 100)
        Simple_window win {{100, 100}, 600, 400, "Images"};

        Image rita {{0,0}, "rita.jpg"};
        Image path {{0,0}, "rita_path.gif"};

        // select a 600 by 400 sub image from path that should be displayed
        // with its upper left corner at the Point (25,250) in path
        path.set_mask({50, 250}, 600, 400); // likely landfall

        // attach images to win
        win.attach(path);
        win.attach(rita);

        win.wait_for_button(); // display
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

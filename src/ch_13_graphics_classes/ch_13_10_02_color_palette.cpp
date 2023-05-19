// program uses the graphics library's Vector_ref class to create and display
// 16 by 16 grid that contains a 256 color, color palette

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
        Simple_window win {{100, 100}, 600, 400, "16 * 16 color matrix"};
        Vector_ref<Rectangle> vr; // to hold unnamed Rectangles

        // fill vr with 256 unnamed Rectangles displayed in win as a 16 by 16
        // grid of of 20 by 20 pixel Rectangles 
        for (int i = 0; i < 16; i++) // row offset
            for (int j = 0; j < 16; j++) // column offset
            {
                // add new Rectangle to collection
                vr.push_back(new Rectangle {{i * 20, j * 20}, 20, 20});

                // set newly added Rectangle's fill_color
                vr[vr.size() - 1].set_fill_color({i * 16 + j});

                // attach newly added Rectangle to win
                win.attach(vr[vr.size() - 1]);
            }

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

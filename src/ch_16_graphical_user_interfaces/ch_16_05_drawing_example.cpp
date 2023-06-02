// program allows a user to display a sequence of lines as specified by a
// sequence of coordinate pairs
//
// program demonstrates how to use the graphics library to create a Window
// specific to program features

#include <iostream> // for cerr
#include <string> // for string
#include <sstream> // for stringstream
#include <exception> // for exception
#include <GUI/Window.hpp> // for Window, x_max(), y_max(), gui_main(), redraw()
#include <GUI/GUI.hpp> // for Address, reference_to<>(), In_box, Out_box,
                       // Button
#include <GUI/Graphics.hpp> // for Open_polyline, Point


// class that represents a Window in which the user can draw lines that connect
// Points as specified by the user
struct Lines_window : Graphics_lib::Window {

    // constructor... initializes this Lines_window to a width of w and height
    // of h pixels with its upper left coorner at xy, a name that corresponds
    // to title, default values for each private attribute, and registers
    // callback functions for each of this Lines_window's actions
    Lines_window(Point xy, int w, int h, const std::string& title);

private:
    Graphics_lib::Open_polyline lines;
    Graphics_lib::Button next_button; // "[Next point]"
    Graphics_lib::Button quit_button; // "[Quit]"
    Graphics_lib::In_box next_x; // "next x:[___]"
    Graphics_lib::In_box next_y; // "next y:[___]"
    Graphics_lib::Out_box xy_out; // "current (x,y):[___]"

    // class method
    // callback for next_button
    // NOTE: Address is synonym for void *
    static void cb_next(Graphics_lib::Address, Graphics_lib::Address);
 
    // the "Next point" button's action... it reads a pair of coordinates,
    // updates this Lines_window's lines member and position readout, and
    // redraws the window
    void next();
    
    // class method
    // NOTE: Address is synonym for void *
    // callback for quit_button
    static void cb_quit(Graphics_lib::Address, Graphics_lib::Address);
    
    // the "Quit" button's action... clicking it, deletes this Lines_window
    void quit()
    {
        hide();
    }
};

// constructor... initializes this Lines_window to a width of w and height
// of h pixels with its upper left coorner at xy, a name that corresponds
// to title, default values for each private attribute, and registers
// callback functions for each of this Lines_window's actions
Lines_window::Lines_window(Point xy, int w, int h, const std::string& title)
    : Window {xy, w, h, title}, // initialize super class
      // private attributes
      next_button {{x_max() - 150, 0}, 70, 20, "Next point", cb_next},
      quit_button {{x_max() - 70, 0}, 70, 20, "Quit", cb_quit},
      next_x {{x_max() - 310, 0}, 50, 20, "next x:"},
      next_y {{x_max() - 210, 0}, 50, 20, "next y:"},
      xy_out {{100, 0}, 100, 20, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
}

// callback function for the "[Quit]" Button
void Lines_window::cb_quit(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).quit();
    // static_cast<Lines_window *>(wid)->quit();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).quit();
}

// callback function for the "[Next point]" Button
void Lines_window::cb_next(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).next();
    // static_cast<Lines_window *>(wid)->next();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).next();
}

// the "Next point" button's action... it reads a pair of coordinates,
// updates this Lines_window's lines member and position readout, and
// redraws the window
void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add({x, y});

    // update current position readout:
    std::stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main(void)
{
    using std::exception;
    using std::cerr;

    try
    {
        Lines_window win {{100, 100}, 600, 400, "lines"};
        return Graphics_lib::gui_main();
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
}

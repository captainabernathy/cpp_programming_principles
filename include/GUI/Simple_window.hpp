#ifndef SIMPLE_WINDOW_HPP
#define SIMPLE_WINDOW_HPP

#include <string> // for string
#include <GUI/Window.hpp> // for Window
#include <GUI/Point.hpp> // for Point
#include <GUI/GUI.hpp> // for Button, Address, reference_to<>


// NOTE: it is necessary derive from Graph_lib::Window bc it is the class that
// (through FLTK) connects the notion of a window to the system's windowing
// implementation

// a Simple_window is simply a Window that contains a "Next" Button
struct Simple_window : Graphics_lib::Window {

    // constructor... builds a Simple_window of width by height pixels with its
    // upper-left corner at xy, a name that corresponds to title, and default
    // values for each private attribute
    Simple_window(Point xy, int width, int height, const std::string& title)
        : Graphics_lib::Window(xy, width, height, title), // initialize parent
          // initialize "Next" Button
          next_button({x_max() - 70, 0}, // Button's position in Window
                      70, // Button's width
                      20, // Button's height
                      "Next", // Button's label
                      cb_next), // Button's callback
          button_pushed {false} // Button's state
    {
        attach(next_button); // attach() for Widgets (inherited)
    }

    // simple event loop... stops program execution until this Simple_window's
    // "Next" button is pressed and then returns its state
    bool wait_for_button();

private:
    // this Simple_window's "Next" Button
    Graphics_lib::Button next_button;
                        
    // state of this Simple_window's "Next" Button
    bool button_pushed;

    // callback for next_button... called through class
    // NOTE: Address is a synonym for void *
    // first Address is NOT used, second Address is the address of the
    // Simple_window that contains the "Next" Button
    static void cb_next(Graphics_lib::Address, Graphics_lib::Address winptr)
    {
        // static_cast<Simple_window *>(winptr)->next();
        // (*static_cast<Simple_window *>(winptr)).next();
        // same as either of the above
        Graphics_lib::reference_to<Simple_window>(winptr).next();
    }

    // action performed by cb_next() when this Simple_window's "Next" Button
    // is pressed
    void next()
    {
        button_pushed = true; // change button state
        hide(); // removes this Simple_window from the screen
    }
};

#endif

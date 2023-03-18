#include "Simple_window.h"
#include <FL/Fl.H>

Simple_window::Simple_window(Point xy, int w, int h, const std::string& title)
    : Window(xy, w, h, title),
      next_button(Point(x_max() - 70, 0), 70, 20, "Next", cb_next),
      button_pushed(false)
{
    attach(next_button);
}

// modified event loop... handles all events, quits when button_pushed = true
bool Simple_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 1
    // simple handler
    while (!button_pushed)
        Fl::wait();
    Fl::redraw();
#else
    // to handle case where the user presses the X button in the window frame to
    // kill the application, change condition to 0 to enable this branch
    Fl::run();
#endif
    return button_pushed;
}

// call Simple_window::next() for the window located at pw
void Simple_window::cb_next(Graph_lib::Address, Graph_lib::Address pw)
{
    Graph_lib::reference_to<Simple_window>(pw).next();
}

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

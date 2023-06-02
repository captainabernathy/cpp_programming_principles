#include <GUI/Simple_window.hpp>
#include <FL/Fl.H> // for Fl::wait(), Fl::redraw(), Fl::run()
#include <FL/Fl_Window.H> // for show()

// NOTE: Fl is a global (static) class provided by FLTK that contains state
// information and global methods

// simple event loop... stops program execution until this Simple_window's
// "Next" button is pressed and then returns its state
bool Simple_window::wait_for_button()
{
    show(); // display this Simple_window
    button_pushed = false;

    // not a fan of this conditional compilation setup
#if 1
    while (!button_pushed)
        Fl::wait(); // waits until this Simple_window's "Next" Button is pushed
    Fl::redraw(); // redraws all Widgets
#else
    // to handle case where the user presses the "X" button in the window frame
    // to kill the application, change condition to 0 to enable this branch
    Fl::run(); // calls Fl::wait() repeatedly while this Simple_window is
               // displayed
#endif
    return button_pushed;
}


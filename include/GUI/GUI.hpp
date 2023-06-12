#ifndef GUI_HPP
#define GUI_HPP

#include <string> // for string
#include <FL/Fl_Widget.H> // for hide(), show(), position(), Fl_Callback,
                          // Fl_Widget
#include <FL/Fl_Button.H> // for Fl_Button
#include <FL/Fl_Input.H> // for Fl_Input
#include <FL/Fl_Output.H> // for Fl_Output
#include <GUI/Point.hpp> // for Point
#include <GUI/Window.hpp> // for Window
#include <GUI/Graphics.hpp> // for Vector_ref

namespace Graphics_lib {

// typedef void *Address; // address is a synonym for void *
using Address = void *;

// typedef void (*Callback)(Address, Address); // required FLTK callback
using Callback = void (*)(Address, Address);

// function template that returns a the (void *) pointer passed to ptr as a
// reference to a T
template<typename T>
T& reference_to(Address ptr)
{
    // treat an Address (aka void *) as a reference to a T
    return *static_cast<T*>(ptr);
}

// Widget is a handle to an Fl_Widget... NOT an actual Fl_Widget
// Widgets are used to define forms of interaction with a program through a GUI
// NOTE: this Widget class provides abstract base class from which other
// Widgets can be derived by implementing the attach() method
class Widget {
public:
    // constructor... builds a Widget that uses the Callback function cb and is
    // w pixels wide by h pixels high with its upper left corner at xy and the
    // label s
    Widget(Point xy, int w, int h, std::string const& s, Callback cb)
        : loc {xy},
          width {w},
          height {h},
          label {s},
          do_it {cb} {  }

    // makes this Widget invisible
    virtual void hide()
    {
        widptr->hide();  // wraps Fl_Widget::hide()
    }

    // makes this Widget visible
    virtual void show()
    {
        widptr->show(); // wraps Fl_Widget::show()
    }

    // moves this Widget dx pixels in the horizontal direction and dy pixels
    // in the vertical direction
    virtual void move(int dx, int dy)
    {
        hide(); // make this Widget invisible
        // wraps Fl_Widget::position()
        widptr->position(loc.x += dx, loc.y += dy); // reposition this Widget
        show(); // make this Widget visible again
    }

    virtual void attach(Window&) = 0;

    Point loc; // location of this Widget's upper left corner
    int width; // this Widget's width
    int height; // this Widget's height
    std::string label; // this Widget's label
    Callback do_it; // this Widget's Callback function

    // destructor
    virtual ~Widget() {  }

    // prevent copying
    Widget& operator=(Widget const&) = delete;
    Widget(Widget const&) = delete;

protected:
    Window *own; // pointer to the Window this Widget belongs to
    Fl_Widget *widptr; // pointer to the Fl_Widget this Widget runs through
};

// a Button is a Widget that provides a handle to an Fl_Button
struct Button : Widget {
    // constructor... builds a Button that uses the Callback function cb and is
    // w pixels wide by h pixels high with its upper left corner at xy and the
    // label s
    Button(Point xy, int w, int h, std::string const& label, Callback cb)
        : Widget {xy, w, h, label, cb} {  }

    // connects this Button to the Window win
    void attach(Window& win)
    {
        // initialize this Button's Fl_Widget pointer to a new Fl_Button
        widptr = new Fl_Button {loc.x, loc.y, width, height, label.c_str()};
        // use widptr to call this Button's Callback function on win
        widptr->callback(reinterpret_cast<Fl_Callback*>(do_it), &win);
        own = &win; // initialize this Button's Window pointer
    }
};

// an In_box is a Widget that can accept text typed into it that can be
// subsequently read back as a string or an int
struct In_box : Widget {
    // constructor... builds an In_box that is w pixels wide by h pixels high
    // with its upper left corner at xy and the label s
    In_box(Point xy, int w, int h, std::string const& s)
        : Widget {xy, w, h, s, nullptr} {  }

    // returns the integer typed into this In_box... or -999999 if this In_box
    // does not contain an integer
    int get_int();

    // returns the text typed into this In_box... or the empty string if this
    // In_box contains no text
    // NOTE: NOT IMPLEMENTED
    std::string get_string();

    // connects this In_box to the Window win
    void attach(Window& win)
    {
        // initialize this In_box's Fl_Widget pointer to a new Fl_Input
        widptr = new Fl_Input {loc.x, loc.y, width, height, label.c_str()};
        own = &win; // initialize this In_box's Window pointer
    }
};

// an Out_box is a Widget that displays a message that consists of a a string
// or an int to the user
struct Out_box : Widget {
    // constructor... builds an Out_box that is w pixels wide by h pixels high
    // with its upper left corner at xy and the label s
    Out_box(Point xy, int w, int h, std::string const& s)
        : Widget {xy, w, h, s, nullptr} {  }

    // writes i to this Out_box
    // NOTE: NOT IMPLEMENTED
    void put(int i);

    // writes s to this Out_box
    void put(std::string const& s)
    {
        // (*static_cast<Fl_Output *>(widptr)).value(s.c_str());
        // static_cast<Fl_Output *>(widptr)->value(s.c_str());
        // same as either of the above
        reference_to<Fl_Output>(widptr).value(s.c_str());
    }

    // connects this Out_box to the Window win
    void attach(Window& win)
    {
        // initialize this Out_box's Fl_Widget pointer to a new Fl_Output
        widptr = new Fl_Output {loc.x, loc.y, width, height, label.c_str()};
        own = &win; // initialize this Out_box's Window pointer
    }
};

// a Menu is a Widget that contains a vector of Buttons that can be arranged
// either horizontally or vertically
struct Menu : Widget {
    // enum that's used identify a Widgets orientation
    enum Kind { horizontal, vertical };

    // constructor... builds a Menu that is w pixels wide by h pixels high with
    // its upper left corner at xy, label s, and oriented according to ki
    Menu(Point xy, int w, int h, Kind ki, std::string const& label)
        : Widget {xy, w, h, label, nullptr},
          k {ki},
          offset {0} {  }

    // vector of Buttons that this Menu contains
    Vector_ref<Button> selection;
    Kind k; // this Menu's orientation
    // pixel offset applied to this Menu with respct to its orientation
    int offset;

    // attaches b to this Menu and returns b's position in this Menu's
    // Vector_ref of Buttons
    int attach(Button& b); // Menu does not delete &b

    // attaches a new Botton (p) to this Menu and returns p's position in this
    // Menu's Vector_ref of Buttons
    int attach(Button *p); // Menu deletes p

    // makes each Button in this Menu visible
    void show()
    {
        // loop over each Button in this Menu... and call its show() method
        for (size_t i = 0; i < selection.size(); i++)
            selection[i].show();
    }

    // makes each Button in this Menu invisible
    void hide()
    {
        // loop over each Button in this Menu... and call its hide() method
        for (size_t i = 0; i < selection.size(); i++)
            selection[i].hide();
    }

    // move each Button in this Menu dx pixels in the horizontal direction and
    // dy pixels in the vertical direction
    void move(int dx, int dy)
    {
        // loop over each Button in this Menu... and call its hide() method
        for (size_t i = 0; i < selection.size(); i++)
            selection[i].move(dx, dy);
    }

    // connects each Button in this Menu to the Window win
    void attach(Window& win)
    {
        // loop over each Button in this Menu... and call its attach() method
        for (size_t i = 0; i < selection.size(); i++)
            win.attach(selection[i]);

        own = &win; // initialize each Button's Window pointer
    }
};

}

#endif

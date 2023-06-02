#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string> // for string
#include <vector> // for vector
#include <FL/Fl.H> // for Fl::w(), Fl::h(), Fl::run()
#include <FL/Fl_Window.H> // for Fl_Window, copy_label(), show()
#include <FL/Fl_Widget.H> // for size()
#include <FL/Fl_Group.H> // for resizable()
#include <GUI/Point.hpp> // for Point

namespace Graphics_lib {
// forward declarations
class Shape;
class Widget;

class Window : public Fl_Window {

public:
    // builds a Window of w by h pixels named title and lets system pick the
    // location
    Window(int width, int height, std::string const& title)
        : Fl_Window {width, height, title.c_str()},
          w {width},
          h {height}
    {
        init();
    }

    // builds a Window of w by h pixels named title with its top left corner
    // located at the Point xy
    Window(Point xy, int width, int height, std::string const& title)
        : Fl_Window {xy.x, xy.y, width, height, title.c_str()},
          w {width},
          h {height}
    {
        init();
    }

    // destructor
    virtual ~Window() {  }

    // returns the width of this Window
    int x_max() const
    {
        return w;
    }

    // returns the height of this Window
    int y_max() const
    {
        return h;
    }

    // resizes this Window to ww by hh pixels
    void resize(int width, int height)
    {
        w = width;
        h = height;
        size(width, height);
    }

    // sets the name of this Window's title to s
    void set_label(std::string const& s)
    {
        copy_label(s.c_str());
    }

    // connects s to this Window... by adding it to this Window's vector of
    // Shapes
    void attach(Shape& s)
    {
        shapes.push_back(&s);
    }

    // connects wid to this Window
    void attach(Widget& wid);

    // removes s from this Window
    void detach(Shape& s); // remove s from shapes

    // removes wid from this Window (deactivates callback)
    void detach(Widget& wid);

    // put s on top of the other Shapes in this Window
    void put_on_top(Shape& s);

protected:
    // displays this Window
    void draw();

private:
    std::vector<Shape*> shapes; // pointers to Shapes attached to this Window
    int w; // this Window's width
    int h; // this Window's height

    // initializes this Window and puts it on the screen
    void init()
    {
        resizable(this);
        show();
    }
};

// invoke GUI library's main event loop
inline int gui_main()
{
    return Fl::run();
}

// returns the width of screen in pixels
inline int x_max()
{
    return Fl::w();
}

 // returns the height of screen in pixels
inline int y_max()
{
    return Fl::h();
}

}
#endif

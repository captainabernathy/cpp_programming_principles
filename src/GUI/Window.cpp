#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib {

Window::Window(int ww, int hh, const std::string& title)
    : Fl_Window(ww, hh, title.c_str()), w(ww), h(hh)
{
    init();
}

Window::Window(Point xy, int ww, int hh, const std::string& title)
    : Fl_Window(xy.x, xy.y, ww, hh, title.c_str()), w(ww), h(hh)
{
    init();
}

void Window::init()
{
    resizable(this);
    show();
}

void Window::draw()
{
    Fl_Window::draw();
    for (unsigned int i = 0; i < shapes.size(); i++)
        shapes[i]->draw();
}

void Window::attach(Widget& w)
{
    begin(); // FLTK: begin attaching new Fl_Widgets to this window
    w.attach(*this); // let Widget create its Fl_Widgets
    end(); // FLTK: stop attaching new Fl_Widgets to this window
}

void Window::detach(Widget& b)
{
    b.hide();
}

void Window::detach(Shape& s)
{
    // guess that the last attached will be first released
    for (unsigned int i = shapes.size(); 0 < i; i--)
        if (shapes[i - 1] == &s)
            shapes.erase(shapes.begin() + (i - 1));
}

void Window::put_on_top(Shape& p)
{
    for (size_t i = 0; i < shapes.size(); i++)
    {
        if (&p == shapes[i])
        {
            for (i++; i < shapes.size(); i++)
                shapes[i - 1] = shapes[i];

            shapes[shapes.size() - 1] = &p;
            return;
        }
    }
}

int gui_main()
{
    return Fl::run();
}
}
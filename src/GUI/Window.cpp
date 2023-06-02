#include <GUI/Window.hpp>
#include <FL/Fl_Window.H> // for draw()
#include <FL/Fl_Group.H> // for begin(), end()
#include <GUI/Graphics.hpp> // for Shape
#include <GUI/GUI.hpp> // for Widget

namespace Graphics_lib {

// displays this Window
void Window::draw()
{
    Fl_Window::draw(); // wraps Fl_Window::draw()
    
    // loop over each of this Window's Shapes and call their draw method
    for (unsigned int i = 0; i < shapes.size(); i++)
        shapes[i]->draw();
}

// makes wid visible in this Window
void Window::attach(Widget& wid)
{
    begin(); // FLTK: begin attaching new Fl_Widgets to this window
    wid.attach(*this); // let Widget create its Fl_Widgets
    end(); // FLTK: stop attaching new Fl_Widgets to this window
}

// removes wid from this Window (deactivates callback)
void Window::detach(Widget& wid)
{
    wid.hide();
}

// removes s from this Window
void Window::detach(Shape& s)
{
    // guess that the last attached will be first released...
    for (unsigned int i = shapes.size(); 0 < i; i--)
        // whenever s is found, erase it
        if (shapes[i - 1] == &s)
            shapes.erase(shapes.begin() + (i - 1)); // offset of s in shapes
}

// put s on top of the other Shapes in this Window
void Window::put_on_top(Shape& s)
{
    // loop over each of the Shapes in this Window
    for (size_t i = 0; i < shapes.size(); i++)
    {
        // whenver s is found...
        if (&s == shapes[i])
        {
            // move each subsequent Shape down a position
            for (i++; i < shapes.size(); i++)
                shapes[i - 1] = shapes[i];

            // copy s to the top of this Window's Shapes
            shapes[shapes.size() - 1] = &s;
            return;
        }
    }
}

}

// program demonstrates how to use the graphics library's Vector_ref class to
// manage named and unnamed Rectangle objects

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Rectangle

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;
        Vector_ref<Rectangle> rect;

        // x is a named Rectangle
        Rectangle x {{100, 200}, {200, 300}};
        rect.push_back(x); // add named Rectangle x to rect

        // add unnamed Rectangle object to rect
        rect.push_back(new Rectangle {{50, 60}, {80, 90}});

        for (size_t i = 0; i < rect.size(); i++) // use rect
            rect[i].move(10, 10);
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

// program demonstrates how to use the graphics library's Vector_ref class to
// manage named and unnamed Rectangle objects

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

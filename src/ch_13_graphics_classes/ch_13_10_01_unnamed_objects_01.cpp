#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        using namespace Graph_lib;
        Vector_ref<Rectangle> rect;

        Rectangle x(Point(100, 200), Point(200, 300));
        rect.push_back(x); // add named

        // add unnamed
        rect.push_back(new Rectangle(Point(50, 60), Point(80, 90)));

        for (int i = 0; i < rect.size(); i++) // use rect
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

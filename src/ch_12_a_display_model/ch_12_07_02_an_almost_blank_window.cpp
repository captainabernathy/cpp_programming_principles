#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;
using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        Point top_left(100, 100); // top left
        Simple_window win(top_left, 600, 400, "Canvas");
        win.wait_for_button(); // give control to display engine
    }
    catch(exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch(...)
    {
        cerr << "undefined exception" << endl;
        return 2;
    }

    return 0;
}

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

        Simple_window win1(Point(100, 100), 600, 400, "two lines");
        Line horizontal(Point(100, 100), Point(200, 100)); // horizontal line
        Line vertical(Point(150, 50), Point(150, 150)); // vertical line

        // attach lines to window
        win1.attach(horizontal);
        win1.attach(vertical);

        win1.wait_for_button(); // display
    }
    catch (exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "undefined exception" << endl;
        return 2;
    }

    return 0;
}

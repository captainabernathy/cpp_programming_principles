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

        Simple_window win1(Point(100, 100), 600, 400, "lines: +");

        Lines x;
        x.add(Point(100, 100), Point(200, 100)); // first line (horizontal)
        x.add(Point(150, 50), Point(150, 150)); // second line (vertical)
        win1.attach(x); // attach lines to window
        win1.wait_for_button(); // display

    }
    catch (exception &ex)
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

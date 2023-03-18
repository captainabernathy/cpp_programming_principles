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

        Simple_window win(Point(100, 100), 600, 400, "Ellipses");

        // pass center point and x and y distances from point
        Ellipse e1(Point(200, 200), 50, 50);
        Ellipse e2(Point(200, 200), 100, 50);
        Ellipse e3(Point(200, 200), 100, 150);

        win.attach(e1);
        win.attach(e2);
        win.attach(e3);

        win.wait_for_button();
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

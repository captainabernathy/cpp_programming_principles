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

        Simple_window win(Point(100, 100), 600, 400, "Circles");

        Circle c1(Point(100, 200), 50);
        Circle c2(Point(150, 200), 100);
        Circle c3(Point(200, 200), 150);

        win.attach(c1);
        win.attach(c2);
        win.attach(c3);

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

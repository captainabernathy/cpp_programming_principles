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

        Simple_window win(Point(100, 100), 600, 400, "Marked polyline");

        Marked_polyline mpl("1234");
        mpl.add(Point(100, 100));
        mpl.add(Point(150, 200));
        mpl.add(Point(250, 250));
        mpl.add(Point(300, 200));

        win.attach(mpl);
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

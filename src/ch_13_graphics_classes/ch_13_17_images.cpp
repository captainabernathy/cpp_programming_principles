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

        Simple_window win(Point(100, 100), 600, 400, "Images");

        Image rita(Point(0,0), "rita.jpg");
        Image path(Point(0,0), "rita_path.gif");
        path.set_mask(Point(50, 250), 600, 400); // likely landfall

        win.attach(path);
        win.attach(rita);

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

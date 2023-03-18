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

        Simple_window win(Point(100, 100), 600, 400, "16 * 16 color matrix");
        Vector_ref<Rectangle> vr;

        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
            {
                vr.push_back(new Rectangle(Point(i * 20, j * 20), 20, 20));
                vr[vr.size() - 1].set_fill_color(i * 16 + j);
                win.attach(vr[vr.size() - 1]);
            }

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

#include <iostream>
#include <stdexcept>
#include "Simple_window.h"
#include "Graph.h"

inline double one(double) { return 1; }
inline double slope(double x) { return x / 2; }
inline double square(double x) { return x * x; }

using std::cerr;
using std::endl;
using std::exception;

int main()
{
    try
    {
        using namespace Graph_lib;
        // window size
        constexpr int xmax = 600;
        constexpr int ymax = 400;

        // origin
        constexpr int x_orig = xmax / 2;
        constexpr int y_orig = ymax / 2;
        const Point orig(x_orig, y_orig);

        // range [-10:11)
        constexpr int r_min = -10;
        constexpr int r_max = 11;

        constexpr int n_points = 400; // points in range

        // scaling factors
        constexpr int x_scale = 30;
        constexpr int y_scale = 30;

        Simple_window win0(Point(100, 100), xmax, ymax, "Function graphing");

        Function s1(one, r_min, r_max, orig, n_points, x_scale, y_scale);
        Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
        Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);

        win0.attach(s1);
        win0.attach(s2);
        win0.attach(s3);

        Text ts(Point(100, y_orig - 40), "one");
        Text ts2(Point(100, y_orig + y_orig / 2 - 20), "x/2");
        Text ts3(Point(x_orig - 100, 20), "x*x");
        win0.attach(ts);
        ts.set_font_size(20);
        win0.attach(ts2);
        ts2.set_font_size(20);
        win0.attach(ts3);
        ts3.set_font_size(20);

        // make the axis a bit smaller than the window
        constexpr int xlength = xmax - 40;
        constexpr int ylength = ymax - 40;

        Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale,
                "one notch == 1");
        Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale,
                "one notch == 1");
        win0.attach(x);
        win0.attach(y);
        x.set_color(Color::red);
        y.set_color(Color::red);
        win0.wait_for_button();
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

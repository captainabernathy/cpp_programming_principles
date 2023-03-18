#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

using std::cerr;
using std::endl;
using std::exception;
using std::cos;

inline double one(double) { return 1; }
inline double slope(double x) { return x / 2; }
inline double square(double x) { return x * x; }
inline double sloping_cos(double x) { return cos(x) + slope(x); }

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
        win0.attach(s1);
        win0.attach(s2);

        Text ts(Point(100, y_orig - 40), "one");
        Text ts2(Point(100, y_orig + y_orig / 2 - 20), "x/2");
        win0.attach(ts);
        ts.set_font_size(20);
        win0.attach(ts2);
        ts2.set_font_size(20);
        win0.set_label("Function graphing: more functions");

        // max axis a bit smaller than the window
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

        Function s4(cos, r_min, r_max, orig, 400, 20, 20);
        s4.set_color(Color::blue);
        Function s5(sloping_cos, r_min, r_max, orig, 400, 20, 20);
        x.label.move(-160, 0);
        x.notches.set_color(Color::dark_red);
        win0.attach(s4);
        win0.attach(s5);

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

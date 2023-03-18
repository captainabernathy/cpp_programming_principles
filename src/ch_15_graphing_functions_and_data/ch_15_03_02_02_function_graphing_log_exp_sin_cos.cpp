#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

using std::cerr;
using std::endl;
using std::exception;
using std::cos;
using std::sin;
using std::log;
using std::exp;

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

        // scaling factors
        constexpr int x_scale = 30;
        constexpr int y_scale = 30;

        Simple_window win0(Point(100, 100), xmax, ymax, "Function graphing");
        Function f1(log, 0.000001, r_max, orig, 200, 30, 30); // log base e
        Function f2(sin, r_min, r_max, orig, 200, 30, 30); // sin()
        f2.set_color(Color::blue);
        Function f3(cos, r_min, r_max, orig, 200, 30, 30);
        Function f4(exp, r_min, r_max, orig, 200, 30, 30); // e^x
        f4.set_color(Color::green);

        win0.attach(f1);
        win0.attach(f2);
        win0.attach(f3);
        win0.attach(f4);

        win0.set_label("log, exp, sin, and cos");

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
        x.label.move(-160, 0);
        x.notches.set_color(Color::dark_red);
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

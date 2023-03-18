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

        // range [-10:11]
        constexpr int r_min = -10;
        constexpr int r_max = 11;

        constexpr int n_points = 400; // points used in range

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
        win0.wait_for_button();

    } catch (exception& ex)
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

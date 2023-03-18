#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

using std::cerr;
using std::endl;
using std::exception;
using std::pow;
using std::exp;
using std::ostringstream;

int factorial(int n);
double term(double x, int n);
double expe(double x, int n);
double expN(double x);

double expN_num_terms = 10;

int main(void)
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

        // make axes a bit smaller than the window
        constexpr int xlength = xmax - 40;
        constexpr int ylength = ymax - 40;

        Simple_window win(Point(100, 100), xmax, ymax, "exp approximation");
        Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale,
                "one notch == 1");
        Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale,
                "one notch == 1");
        win.attach(x);
        win.attach(y);
        x.set_color(Color::red);
        y.set_color(Color::red);

        Function real_exp(exp, r_min, r_max, orig, 200, x_scale, y_scale);
        real_exp.set_color(Color::blue);
        win.attach(real_exp);

        for (int n = 0; n < 50; n++)
        {
            ostringstream ss;
            ss << "exp approximation; n==" << n;
            win.set_label(ss.str());
            expN_num_terms = n;

            // get next approximation
            Function e(expN, r_min, r_max, orig, 200, x_scale, y_scale);
            win.attach(e);
            if (!win.wait_for_button())
                break; // user asked to quit
            win.detach(e);
        }
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

double expN(double x)
{
    return expe(x, expN_num_terms);
}

double expe(double x, int n)
{
    double sum = 0.;
    for (int i = 0; i < n; i++)
        sum += term(x, i);
    return sum;
}

double term(double x, int n)
{
    return pow(x, n) / factorial(n);
}

int factorial(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        --n;
    }
    return r;
}

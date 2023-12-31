// program demonstrates how to use the graphic library's Function class to
// graph functions

#include <iostream> // for cerr
#include <exception> // for exception
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Point, Function

// functions to plot
// function that maps its input to 1... f(x) = 1
inline double one(double) { return 1; } // horizontal line at y = 1

// function that maps each input passed to x to x/2... f(x) = x/2
inline double slope(double x) { return x / 2; } // sloping line

// function that maps each input passed to x to x^2... f(x) = x^2
inline double square(double x) { return x * x; } // parabola

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using namespace Graphics_lib;

        // window size
        constexpr int x_max = 600;
        constexpr int y_max = 400;

        // origin... half-way between the max x and y ranges
        constexpr int x_orig = x_max / 2;
        constexpr int y_orig = y_max / 2;
        const Point orig {x_orig, y_orig};

        // function ranges [-10:11)
        constexpr int r_min = -10;
        constexpr int r_max = 11;

        constexpr int n_points = 400; // points used in range

        // scaling factors
        constexpr int x_scale = 30;
        constexpr int y_scale = 30;

        // create a 600 by 400 window with an upper left corner at (100,100)
        Simple_window win0 {{100, 100}, x_max, y_max, "Function graphing"};

        // shape that plots the function one() within the range [r_min, r_max)
        // with its origin at orig using n_points line segments scaled by
        // x_scale and y_scale
        Function f1 {one, r_min, r_max, orig, n_points, x_scale, y_scale};

        // shape that plots the function slope() within the range
        // [r_min, r_max) with its origin at orig using n_points line segments
        // scaled by x_scale and y_scale
        Function f2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};

        // shape that plots the function square() within the range
        // [r_min, r_max) with its origin at orig using n_points line segments
        // scaled by x_scale and y_scale
        Function f3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};

        // attach Functions to window
        win0.attach(f1);
        win0.attach(f2);
        win0.attach(f3);

        win0.wait_for_button(); // give control to display manager
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

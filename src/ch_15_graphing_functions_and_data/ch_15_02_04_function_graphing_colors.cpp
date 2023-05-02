// program demonstrates how to use the graphics library's Axis object to change
// the color of the axes in a window that contains labeled Functions

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors

// functions to plot
// function that maps its input to 1... f(x) = 1
inline double one(double) { return 1; }

// function that maps each input passed to x to x/2... f(x) = x/2
inline double slope(double x) { return x / 2; }

// function that maps each input passed to x to x^2... f(x) = x^2
inline double square(double x) { return x * x; }

int main()
{
    using std::cerr;
    using std::endl;
    using std::exception;

    try
    {
        using namespace Graph_lib;

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

        constexpr int n_points = 400; // points in range

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

        // create some Text labels for each Function
        Text tf1 {{100, y_orig - 40}, "one"};
        Text tf2 {{100, y_orig + y_orig / 2 - 20}, "x/2"};
        Text tf3 {{x_orig - 100, 20}, "x*x"};

        // attach Text label tf1 to window
        win0.attach(tf1);

        // set font size for Text label tf1
        // tf1.set_font_size(20);

        // attach Text label tf2 to window
        win0.attach(tf2);

        // set font size for Text label tf2
        // tf2.set_font_size(20);

        // attach Text label tf3 to window
        win0.attach(tf3);

        // set font size for Text label tf3
        // tf3.set_font_size(20);

        // x Axis length
        constexpr int x_length = x_max - 40;

        // y Axis length
        constexpr int y_length = y_max - 40;

        // create a horizontal Axis starting at (20,y_max/2) of length x_length
        // with x_length / x_scale notches and the label "one notch == 1"
        Axis x {Axis::x, {20, y_orig}, x_length, x_length / x_scale,
                "one notch == 1"};

        // create a vertical Axis starting at (x_max/2,y_length+20) of length
        // y_length with y_length/y_scale notches and the label
        // "one notch == 1"
        Axis y {Axis::y, {x_orig, y_length + 20}, y_length, y_length / y_scale,
                "one notch == 1"};

        win0.attach(x); // attach x Axis to window
        win0.attach(y); // attach y Axis to window

        x.set_color(Color::red); // change x Axis's Color
        y.set_color(Color::red); // change y Axis's Color

        // change window title
        win0.set_label("Function graphing: use color");
        win0.wait_for_button(); // give control to display manager
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

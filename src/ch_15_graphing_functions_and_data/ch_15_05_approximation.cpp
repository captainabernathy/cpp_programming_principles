// program demonstrates how to use the graphics library's Function class to
// approximate the results of a mathematical function that takes a double and
// returns a double

#include "Simple_window.hpp" // provides access to our simple window library
#include "Graph.hpp" // provides access to our graphics library
#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors
#include <cmath> // for exp(), pow()
#include <sstream> // provides stream classes for operating on strings

// computes the nth factorial and returns the result
double factorial(int n);

// computes an exponential term as x^n/n! and returns the result
double term(double x, int n);

// approximates the e^x with n terms of precision
double expe(double x, int n);

// returns an approximation of e^x
double expN(double x);

// number of terms used to compute e^x
double expN_num_terms = 10;

int main(void)
{
    using std::cerr;
    using std::endl;
    using std::exception;
    using std::pow;
    using std::exp;
    using std::ostringstream;

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

        // range [-10:11)
        constexpr int r_min = -10;
        constexpr int r_max = 11;

        constexpr int n_points = 200; // points in range

        // scaling factors
        constexpr int x_scale = 30;
        constexpr int y_scale = 30;

        // x Axis length
        constexpr int x_length = x_max - 40;

        // y Axis length
        constexpr int y_length = y_max - 40;

        // create a 600 by 400 window with an upper left corner at (100,100)
        Simple_window win {{100, 100}, x_max, y_max, "exp approximation"};

        // create a horizontal Axis starting at (20,y_max/2) of length x_length
        // with x_length / x_scale notches and the label "one notch == 1"
        Axis x {Axis::x, {20, y_orig}, x_length, x_length / x_scale,
                "one notch == 1"};

        // create a vertical Axis starting at (x_max/2,y_length+20) of length
        // y_length with y_length/y_scale notches and the label
        // "one notch == 1"
        Axis y {Axis::y, {x_orig, y_length + 20}, y_length, y_length / y_scale,
                "one notch == 1"};
        
        win.attach(x); // attach x Axis to window
        win.attach(y); // attach y Axis to window
        
        x.set_color(Color::red); // change x Axis's Color
        y.set_color(Color::red); // change y Axis's Color

        // shape that plots the function exp() within the range [r_min, r_max)
        // with its origin at orig using n_points line segments  scaled by
        // x_scale and y_scale
        Function real_exp {exp, r_min, r_max, orig, n_points, x_scale,
                           y_scale};
        
        real_exp.set_color(Color::blue); // change Function's real_exp's Color
        
        // attach Function to window
        win.attach(real_exp);

        for (int n = 0; n < 50; n++)
        {
            ostringstream ss;
            ss << "exp approximation; n==" << n;
            win.set_label(ss.str());
            
            // updates global variable expN_num_terms
            expN_num_terms = n;

            // get next approximation
            Function e {expN, r_min, r_max, orig, n_points, x_scale, y_scale};
            
            // draw approximation
            win.attach(e);
            
            if (!win.wait_for_button())
                break; // user asked to quit

            // NOTE: detach() ensures that the window does not try to draw
            // a destroyed object
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

// returns an approximation of e^x
double expN(double x)
{
    return expe(x, expN_num_terms);
}

// approximates the e^x with n terms of precision
double expe(double x, int n)
{
    double sum = 0.; // start
    for (int i = 0; i < n; i++)
        sum += term(x, i); // accumulate successive approximations of e^i
    return sum;
}

// computes an exponential term as x^n/n! and returns the result
double term(double x, int n)
{
    return pow(x, n) / factorial(n);
}

// computes the nth factorial and returns the result
double factorial(int n)
{
    double r = 1.; // start
    while (n > 1)
    {
        r *= n; // accumulate n factorial terms
        --n;
    }
    return r;
}

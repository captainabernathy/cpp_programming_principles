// program demonstrates how to use various classes from the graphics library
// to plot data read from a file

#include <ios> // for ios_base
#include <istream> // for istream
#include <iostream> // for cerr
#include <fstream> // for ifstream
#include <exception> // for exception
#include <string> // for string
#include <GUI/Simple_window.hpp> // for Simple_window
#include <GUI/Graphics.hpp> // for Open_polyline, Axis, Point, Line,
                            // Line_style, Text, Color

// class that contains an attribute for each field contained in a line of the
// file japanese-age.data.txt
struct Distribution {
    int year;
    int young;
    int middle;
    int old;
};

// class that converts a data value to a scaled coordinate
class Scale {
    int coord_base; // coordinate base
    int val_base;   // base of values
    double scale;   // scale factor

public:
    // builds a Scale object with coord_base b, val_base vb, and scale s
    Scale(int b, int vb, double s)
        : coord_base {b}, val_base {vb}, scale {s} {  }

    // overloaded function call operator... returns the coordinate of v
    // based on this Scale
    int operator()(int v) const
    {
        return coord_base + (v - val_base) * scale;
    }
};

// overloaded input operator for a Distribution
// assumes format: ( year : young middle old )
std::istream& operator>>(std::istream& is, Distribution& d);

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::string;
        using std::ifstream;

        using namespace Graphics_lib;

        // window size
        constexpr int x_max = 600;
        constexpr int y_max = 400;

        constexpr int x_offset = 100; // distance from lhs of window to y axis
        constexpr int y_offset = 60;  // distance from bottom of win to x axis

        // space beyond each axis
        constexpr int x_space = 40;
        constexpr int y_space = 40;

        // length of axes
        constexpr int x_length = x_max - x_offset - x_space;
        constexpr int y_length = y_max - y_offset - y_space;

        // range of values represented on the x axis
        constexpr int base_year = 1960;
        constexpr int end_year = 2040;

        // horizontal scaling factor
        constexpr double x_scale = double(x_length) / (end_year - base_year);

        // vertical scaling factor
        constexpr double y_scale = double(y_length) / 100;

        // build a Scale to plot data along the x Axis... with
        // a coord_offset of x_offset, a val_offset of base_year, and
        // a scale of x_scale
        Scale xs {x_offset, base_year, x_scale};

        // build a Scale to plot data along the y Axis... with
        // a coord_offset of y_max - y_offset, a val_offset of 0, and
        // a scale of -y_scale (since y coordinates go downard)
        Scale ys {y_max - y_offset, 0, -y_scale};

        string file_name = "japanese-age-data.txt"; // file to read
        
        // create an input stream associated with the file
        ifstream ifs {file_name.c_str()};

        if (!ifs) // don't read on a bad stream
            error("can't open: ", file_name);

        // lines to graph
        Open_polyline children;
        Open_polyline adults;
        Open_polyline aged;

        // each line contains a distribution
        Distribution d;
        while (ifs >> d)
        {
            // ensure year attribute is in range
            if (d.year < base_year || end_year < d.year)
                error("year out of range");

            // validate distribution data
            if (d.young + d.middle + d.old != 100)
                error("percentages don't add up");

            int x = xs(d.year); // scaled x coordinate

            // add scaled coordinates to each line
            children.add({x, ys(d.young)});
            adults.add({x, ys(d.middle)});
            aged.add({x, ys(d.old)});
        }

        // create a 600 by 400 window with an upper left corner at (100,100)
        Simple_window win {{100, 100}, x_max, y_max, "Aging Japan"};
        
        // create a horizontal Axis starting at (x_offset,y_max-y_offset) of
        // length x_length with (end_year-base)/10 notches and a label that
        // corresponds to the data
        Axis x {Axis::x, {x_offset, y_max - y_offset}, x_length,
                (end_year - base_year) / 10,
                "year   1960  1970     1980     1990     2000     2010     2020"
                "      2030     2040"};
        
        // movel x Axis's label 100 pixels to the left
        x.label.move(-100, 0);
        // x.label.set_font_size(20);

        // create a vertical Axis starting at (x_offset,y_max-y_offset) of
        // length y_length with 10 notches and the label that corresponds to
        // the data
        Axis y {Axis::y, {x_offset, y_max - y_offset}, y_length, 10,
                "% of population"};
        
        // create a Line that runs from a scaled offset of
        // (xs(2009),ys(0)) to (xs(2009),ys(100))
        Line current_year {{xs(2009), ys(0)}, {xs(2009), ys(100)}};
        
        // set current_year's Line_style to dashed
        current_year.set_style(Line_style::dash);

        // create a Text labels for each line in the distribution
        // Text label for the line children
        Text children_label {{20, children.point(0).y}, "age 0-14"};
        
        // set line Color for children
        children.set_color(Color::red);

        // set Text Color for children_label
        children_label.set_color(Color::red);
        // children_label.set_font_size(20);

        // Text label for the line adults
        Text adults_label {{20, adults.point(0).y}, "age 15-64"};
        
        // set line Color for adults
        adults.set_color(Color::blue);

        // set Text Color for adults_label
        adults_label.set_color(Color::blue);
        // adults_label.set_font_size(20);

        // Text label for the line aged
        Text aged_label({20, aged.point(0).y}, "age 65+");
        
        // set line Color for aged
        aged.set_color(Color::dark_green);

        // set Text color for aged_label
        aged_label.set_color(Color::dark_green);
        // aged_label.set_font_size(20);

        // attach objects to window
        win.attach(children);
        win.attach(adults);
        win.attach(aged);
        win.attach(children_label);
        win.attach(adults_label);
        win.attach(aged_label);
        win.attach(x);
        win.attach(y);
        win.attach(current_year);

        win.wait_for_button(); // give control to display manager
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
}

// overloaded input operator for a Distribution
// assumes format: ( year : young middle old )
std::istream& operator>>(std::istream& is, Distribution& d)
{
    char ch1 = 0;
    char ch2 = ch1;
    char ch3 = ch2;
    Distribution dd;

    if (is >> ch1 >> dd.year
           >> ch2 >> dd.young >> dd.middle >> dd.old
           >> ch3)
    {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')')
        {
            is.clear(std::ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d = dd;
    return is;
}

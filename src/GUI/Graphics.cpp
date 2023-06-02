#include <GUI/Graphics.hpp>
#include <string> // for string
#include <algorithm> // for transform()
#include <fstream> // for ifstream
#include <utility> // for pair
#include <cctype> // for tolower()
// #include <climits> // for INT_MAX, INT_MIN
#include <FL/fl_draw.H> // for fl_line(), Fl_Color, fl_color(), fl_line_style(),
                        // fl_begin_complex_polygon(), fl_vertex(),
                        // fl_end_complex_polygon(), fl_draw(), fl_rectf(),
                        // fl_rect(), fl_arc(), fl_font(), fl_size()
#include <FL/Fl_GIF_Image.H> // for Fl_GIF_Image
#include <FL/Fl_JPEG_Image.H> // for Fl_JPEG_Image
#include <GUI/gui_facilities.hpp> // for error()

namespace Graphics_lib {

// draws lines from each Point in this Shape to another as long as this Shape
// is visible and consists of at least two Points
void Shape::draw_lines() const
{
    if (color().visibility() && 1 < points.size()) // draw sole pixel
        // loop over lines starting from the second Point
        for (size_t i = 1; i < points.size(); i++)
            // then draw a line that connects the previous Point to the
            // current point using FLTK's fl_line() function
            fl_line(points[i - 1].x, points[i - 1].y,
                    points[i].x, points[i].y);
}

// draws lines from each Point in this Shape to another as long as this Shape
// is visible and consists of at least two Points
void Shape::draw() const
{
    Fl_Color oldc = fl_color(); // get the last color set

    // there's no good, portable way of retrieving the current style
    // fl_color(lcolor.as_int()); // set color
    fl_color(lcolor.get_fl_color()); // set this Shape's color

    fl_line_style(ls.style(), ls.width()); // set this Shape's Line_style

    draw_lines(); // actually draw this Shape

    fl_color(oldc); // reset this Shape's color... to previous Fl_Color

    fl_line_style(0); // reset this Shape's Line_style to default
}

// move every Point's x component by dx and y component by dy in this
// Shape's vector of points
// move shape += dx and += dy
void Shape::move(int dx, int dy)
{
    // loop over this Shape's Points
    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].x += dx; // update Point's x coordinate
        points[i].y += dy; // update Point's y coordinate
    }
}

// draws the Lines added to this Lines object with add() by connecting each
// pair of Points provided that this Lines object is visible
// draw lines connecting pairs of points
void Lines::draw_lines() const
{
    if (color().visibility())
        // loop over each pair of points in this Lines object
        for (size_t i = 1; i < number_of_points(); i += 2)
            // then draw a line that connects the previous pair of points to
            // the current pair of points using FLTK's fl_line() function
            fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
}

// if the lines (p1, p2) and (p3, p4) intersect, return the distance of the
// intersection point as distances from p1
static std::pair<double, double> line_intersect(Point p1, Point p2, Point p3,
                                                Point p4, bool& parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    // (x2-x1) | (y2 - y1)
    // (x4-x3) | (y4 - y3)
    // take determinant of ^^^ to get the denominator
    double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    // if the denominator is 0, the lines are parallel
    if (denom == 0.) // NOT the best test... should have some some tolerance
    {
        parallel = true; // update reference
        return std::pair<double, double>(0., 0.);
    }

    parallel = false;

    return std::pair<double, double>(
            ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
            ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

// tests the intersection b/t two line segments, and returns true if the two
// segments intersect... in which case the Point intersection is set to the
// point of intersection
static bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4,
                                   Point& intersection)
{
    bool parallel;
    std::pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
    if (parallel || u.first < 0 || u.first > 1 || u.second < 0
        || u.second > 1)
        return false;

    intersection.x = p1.x + u.first * (p2.x - p1.x);
    // intersection.y = p1.y + u.first * (p2.y - p1.y);
    intersection.y = p1.y + u.second * (p2.y - p1.y);
    return true;
}

// adds Point p to this Polygon
void Polygon::add(Point p)
{
    size_t np = number_of_points();

    // check that the new line isn't parallel to the previous one
    if (1 < np)
    {
        // NOTE: an attempt to add a Point to this Polygon that is the same as
        // the previous Point is invalid
        if (p == point(np - 1))
            error("polygon point equal to previous point");

        bool parallel;

        // determine if the lines formed by the previous Point and p and the
        // previous two Points intersect or are parallel
        line_intersect(point(np - 1), p, point(np - 2), point(np - 1),
                       parallel);

        if (parallel)
            error("two polygon points lie in a straight line");
    }

    // be careful... np - 1 is SIZE_MAX when np is 0
    if (np > 0)
        // check that new segment doesn't intersect an old point
        // loop over this Polygon's points excluding its first and last points
        for (size_t i = 1; i < np - 1; i++)
        {
            Point ignore {0, 0};

            // determine if the line segment formed by the previous Point and p
            // intersects with the line segment formed by the current Point and
            // the one before it
            if (line_segment_intersect(point(np - 1), p, point(i - 1),
                                       point(i), ignore))
                error("intersect in polygon");
        }

    // add a Point to this Polygon... qualification with Closed_polygon:: is
    // necessary to avoid recursively calling this function
    Closed_polyline::add(p);
}

// draws and possibly fills this Polygon provided it consists of at least three
// points
void Polygon::draw_lines() const
{
    if (number_of_points() < 3)
        error("less than 3 points in a Polygon");
    Closed_polyline::draw_lines();
}

// draws this Open_polyline provided that its line Color is visible... also
// fills this Open_polyline provided that its fill Color is visible
void Open_polyline::draw_lines() const
{
    // if this Open_polyline needs to be filled
    if (fill_color().visibility())
    {
        // fl_color(fill_color().as_int());
        fl_color(fill_color().get_fl_color());

        // start drawing a filled convex polygon
        fl_begin_complex_polygon();

        // loop over each of the Points in this Open_polyline...
        for (size_t i = 0; i < number_of_points(); i++)
            // add each Point to the current polygon path
            fl_vertex(point(i).x, point(i).y);

        // stop drawing a filled convex polygon
        fl_end_complex_polygon();

        // set fill color for subsequent drawing operations
        // fl_color(color().as_int()); // reset color
        fl_color(color().get_fl_color()); // reset color
    }

    // draw this Open_polyline's outline if its Line color is visible
    if (color().visibility())
        Shape::draw_lines();
}

// draws this Closed_polyline provided it contains more than two points and
// its line Color is visible... also fills this Closed_polyline provided its
// fill Color is visible
void Closed_polyline::draw_lines() const
{
    // first draw the open polyline part
    Open_polyline::draw_lines();

    // then draw the closing line
    if (2 < number_of_points() && color().visibility())
        // draw a line that connects the last Point in this Closed_polyline
        // to its first Point using FLTK's fl_line() function
        fl_line(point(number_of_points() - 1).x,
                point(number_of_points() - 1).y,
                point(0).x, point(0).y);
}

// helper function... draws the single mark c at xy
static void draw_mark(Point xy, char c)
{
    // mark x and y offsets
    static const int dx = 4;
    static const int dy = 4;

    std::string m(1, c); // convert mark to a string
    // draw mark
    fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
}

// draws this Marked_polyline
void Marked_polyline::draw_lines() const
{
    // draw shape of object
    Open_polyline::draw_lines();

    // loop over the number of points in this Marked_polyline and draw a
    // mark at each
    for (size_t i = 0; i < number_of_points(); i++)
        draw_mark(point(i), mark[i % mark.size()]);
}

// draws and possibly fill this rectangle
void Rectangle::draw_lines() const
{
    if (fill_color().visibility())
    {
        // set fill color for subsequent drawing operations
        // fl_color(fill_color().as_int());
        fl_color(fill_color().get_fl_color());

        // fill this Rectangle providing FLTK's fl_rectf() function with this
        // Rectangle's upper-leftmost Point and its width and height
        fl_rectf(point(0).x, point(0).y, w, h);
    }

    // lines on top of fill
    if (color().visibility())
    {
        // set fill color for subsequent drawing operations
        // fl_color(color().as_int());
        fl_color(color().get_fl_color());

        // draw this Rectangle's enclosing lines by providing FLTK's fl_rect()
        // function with this Rectangle's upper-leftmost Point and its width
        // and height
        fl_rect(point(0).x, point(0).y, w, h);
    }
}

// draws this Circle if it is visible
void Circle::draw_lines() const
{
    if (color().visibility())
        // draw a circle that fits in a bounding box defined by an upper-left
        // point with a width and height equal to this Circle's diameter
        fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
}

// draws this Ellipse if it is visible
void Ellipse::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
}

// draws this Text object's string label/contents
void Text::draw_lines() const
{
    // get the current font face and size
    int ofnt = fl_font();
    int osz = fl_size();

    // set the current font face and size
    // fl_font(fnt.as_int(), fnt_sz);
    fl_font(fnt.get_fl_font(), fnt_sz);

    // draw this Text object's string label/contents
    fl_draw(lab.c_str(), point(0).x, point(0).y);

    // (re-)set current font face and size
    fl_font(ofnt, osz);
}

// builds an Axis with Orientation d starting at xy extending for length pixels
// with num_notches notches and the label lab
Axis::Axis(Orientation d, Point xy, int length, int num_notches,
           std::string lab)
    : label {{0, 0}, lab}
{
    // an axis must have a length >= 0
    if (length < 0)
        error("bad axis length");

    switch (d) // evaluate orientation
    {
        case Axis::x: // x axis
            {
                // axis line
                Shape::add(xy); // starting point
                Shape::add({xy.x + length, xy.y}); // ending point

                if (1 < num_notches) // need to add some notches
                {
                    // distance b/t notches
                    int dist = length / num_notches;

                    // advance past Point xy in x direction... initializes
                    // x coordinate of first notch Point
                    int x = xy.x + dist;

                    // loop over num_notches and add a notch for each to this
                    // Axis' collection of notches
                    for (int i = 0; i < num_notches; i++)
                    {
                        // NOTE: remember (0,0) in window coordinates is the
                        // upper left corner, and (xmax, ymax) is the lower
                        // right corner, so a line segment from (x,x.y) to
                        // (x,xy.y-5) extends upward from x
                        notches.add({x, xy.y}, {x, xy.y - 5});
                        x += dist; // x coordinate for next notch
                    }
                }
                // move this Axis' Text label under the line
                label.move(length / 3, xy.y + 20);
                break;
            }
        case Axis::y: // y axis
            {
                Shape::add(xy); // starting point
                Shape::add({xy.x, xy.y - length}); // ending point

                if (1 < num_notches) // need to add some notches
                {
                    // distance b/t notches
                    int dist = length / num_notches;

                    // advance past Point xy in y direction... initializes
                    // y coordinate of first notch Point
                    int y = xy.y - dist;

                    // loop over num_notches and add a notch for each to this
                    // Axis' collection of notches
                    for (int i = 0; i < num_notches; i++)
                    {
                        // NOTE: remember (0,0) in window coordinates is the
                        // upper left corner, and (xmax, ymax) is the lower
                        // right corner, so a line segment from (xy.x,y) to
                        // (xy.x + 5,y) extends rightward from y
                        notches.add({xy.x, y}, {xy.x + 5, y});
                        y -= dist; // y coordinate for next notch
                    }
                }

                // move this Axis' Text label above the line
                label.move(xy.x - 10, xy.y - length - 10);
                break;
            }
        case Axis::z:
            error("z axis not implemented");
    }
}

// draws this Axis
void Axis::draw_lines() const
{
    // NOTE: since an Axis has three parts, we need to call three functions
    // to manipulate an Axis as a whole
    Shape::draw_lines(); // this Axis' primary line

    // NOTE: calling the draw() function on this Axis's notches and label
    // allows them to be drawn with the color stored in them
    notches.draw(); // notches may have a different color than line
    label.draw(); // label may have different color than line
}

// a Function is a shape that graphs the function y=f(x) in the range [r1:r2)
// with its origin at the Point orig using count line segments scaled by
// x_scale and y_scale in the horizontal and vertical directions, respectively
// NOTE: Fct f is pointer to a function that takes a double and returns a
// double
Function::Function(Fct f, double r1, double r2, Point orig, int count,
                   double x_scale, double y_scale)
{
    if (r2 - r1 <= 0) // validate range
        error("bad graphing range");

    if (count <= 0) // validate count
        error("non-positive graphing count");

    double dist = (r2 - r1) / count; // distance between points
    double r = r1; // start
    // double di_max = INT_MAX + 0.;
    // double di_min = INT_MIN + 0.;

    // loop over the range of points
    for (int i = 0; i < count; i++)
    {
        // add each scaled x and y coordinate to this Function's collection of
        // Points
        // double dx = orig.x + r * x_scale;
        // double dy = orig.y - f(r) * y_scale;
        // if ((dx < di_min) || (dx > di_max) || (dy < di_min) || (dy > di_max))
        //     break;
        // add({int(dx), int(dy)});
        add({orig.x + int(r * x_scale), orig.y - int(f(r) * y_scale)});
        r += dist; // next Point's offset
    }
}

// check if file name exists and can be opened for reading
static inline bool can_open(const std::string& s)
{
    std::ifstream ff {s.c_str()};
    return ff ? true : false;
}

// returns the Encoding associated with s
Suffix::Encoding get_encoding(std::string const& s)
{
    // make a lower-case copy of s
    std::string s_low {s};
    std::transform(s_low.begin(), s_low.end(), s_low.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    // loop over SuffixMap
    for (auto it : SuffixMap)
    {
        size_t len = it.first.length(); // length of current suffix

        // return the corresponding Encoding if its last len letters match
        // the current encoding extension
        if (s_low.length() >= len
            && s_low.substr(s_low.length() - len, len) == it.first)
            return it.second;
    }
    
    return Suffix::none; // no matching Encoding
}

// build an Image with an upper left corner at xy, stored at the path
// file_name, and with an optional suffix
Image::Image(Point xy, std::string s, Suffix::Encoding e)
    : w {0},
      h {0},
      fn {xy, ""}
{
    add(xy); // upper left Point

    if (!can_open(s)) // failed to open image file
    {
        fn.set_label("cannot open \"" + s + '\"');
        p = new Bad_image {30, 20}; // build a Bad_image and return
        return;
    }

    // NOTE: Suffix::none is the default
    if (e == Suffix::none)
        e = get_encoding(s); // lookup this Image's encoding

    // check if known encoding
    switch (e)
    {
        case Suffix::jpg:
            p = new Fl_JPEG_Image {s.c_str()}; // allocate a jpeg
            break;
        case Suffix::gif:
            p = new Fl_GIF_Image {s.c_str()}; // allocate a gif
            break;
        default: // unsupported image encoding
            fn.set_label("unsupported file type \"" + s + '\"');
            p = new Bad_image {30, 20}; // error image
    }
}

// draws this Image
void Image::draw_lines() const
{
    // draw label if this Image has one
    if (fn.label() != "")
        fn.draw_lines();

    if (w && h) // draw Image defined in terms of a masking box
        p->draw(point(0).x, point(0).y, w, h, cx, cy);
    else
        p->draw(point(0).x, point(0).y); // draw entire Image
}

}

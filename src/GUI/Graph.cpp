#include "Graph.h"
#include <cstring>
#include <fstream>
#include <utility>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_JPEG_Image.H>

namespace Graph_lib {

Shape::Shape() :
    lcolor(fl_color()),         // default color for lines and characters
    ls(0),                      // default line style
    fcolor(Color::invisible)    // no fill
{  }

void Shape::add(Point p) // protected method
{
    points.push_back(p);
}

void Shape::set_point(int i, Point p) // not used/necessary so far
{
    points[i] = p;
}

void Shape::draw_lines() const
{
    if (color().visibility() && 1 < points.size()) // draw sole pixel
        for (unsigned int i = 1; i < points.size(); i++)
            fl_line(points[i - 1].x, points[i - 1].y,
                    points[i].x, points[i].y);
}

void Shape::draw() const
{
    Fl_Color oldc = fl_color();
    // there's no good, portable way of retrieving the current style
    fl_color(lcolor.as_int()); // set color
    fl_line_style(ls.style(), ls.width()); // set style
    draw_lines();
    fl_color(oldc); // reset color... to previous
    fl_line_style(0); // reset line style to default
}

// move shape += dx and += dy
void Shape::move(int dx, int dy)
{
    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].x += dx;
        points[i].y += dy;
    }
}

// construct a line from two points
Line::Line(Point p1, Point p2)
{
    add(p1); // add p1 to this shape
    add(p2); // add p2 to this shape
}

void Lines::add(Point p1, Point p2)
{
    Shape::add(p1);
    Shape::add(p2);
}

// draw lines connecting pairs of points
void Lines::draw_lines() const
{
    if (color().visibility())
        for (int i = 1; i < number_of_points(); i += 2)
            fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
}

// do the lines (p1, p2) and (p3, p4) intersect... if so, return the
// distance of the intersect point as distances from p1
inline std::pair<double, double> line_intersect(Point p1, Point p2,
                                                Point p3, Point p4,
                                                bool& parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    if (denom == 0.)
    {
        parallel = true;
        return std::pair<double, double>(0, 0);
    }

    parallel = false;
    return std::pair<double, double>(
            ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
            ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

// intersection b/t two line segments... returns true if the two segments
// intersect... in which case intersection is set to the point of
// intersection
bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4,
                            Point& intersection)
{
    bool parallel;
    std::pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
    if (parallel || u.first < 0 || u.first > 1 || u.second < 0
        || u.second > 1)
        return false;

    intersection.x = p1.x + u.first * (p2.x - p1.x);
    intersection.y = p1.y + u.first * (p2.y - p1.y);
    return true;
}

void Polygon::add(Point p)
{
    int np = number_of_points();

    // check that the new line isn't parallel to the previous one
    if (1 < np)
    {
        if (p == point(np - 1))
            error("polygon point equal to previous point");

        bool parallel;
        line_intersect(point(np - 1), p, point(np - 2), point(np - 1),
                       parallel);

        if (parallel)
            error("two polygon points lie in a straight line");
    }

    // check that new segment doesn't intersect an old point
    for (int i = 1; i < np - 1; i++)
    {
        Point ignore(0, 0);
        if (line_segment_intersect(point(np - 1), p, point(i - 1), point(i),
                                   ignore))
            error("intersect in polygon");
    }

    Closed_polyline::add(p);
}

void Polygon::draw_lines() const
{
    if (number_of_points() < 3)
        error("less than 3 points in a Polygon");
    Closed_polyline::draw_lines();
}

void Open_polyline::draw_lines() const
{
    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();

        for (int i = 0; i < number_of_points(); i++)
            fl_vertex(point(i).x, point(i).y);

        fl_end_complex_polygon();
        fl_color(color().as_int()); // reset color
    }

    if (color().visibility())
        Shape::draw_lines();
}

void Closed_polyline::draw_lines() const
{
    // first draw the open polyline part
    Open_polyline::draw_lines();
    // then draw the closing line
    if (color().visibility())
        fl_line(point(number_of_points() - 1).x,
                point(number_of_points() - 1).y,
                point(0).x, point(0).y);
}

void draw_mark(Point xy, char c)
{
    static const int dx = 4;
    static const int dy = 4;

    std::string m(1, c);
    fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
}

void Marked_polyline::draw_lines() const
{
    Open_polyline::draw_lines();
    for (int i = 0; i < number_of_points(); i++)
        draw_mark(point(i), mark[i % mark.size()]);
}

void Rectangle::draw_lines() const
{
    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x, point(0).y, w, h);
    }

    // lines on top of fill
    if (color().visibility())
    {
        fl_color(color().as_int());
        fl_rect(point(0).x, point(0).y, w, h);
    }
}

// center and radius
Circle::Circle(Point p, int rr)
    : r(rr)
{
    add(Point(p.x - r, p.y - r)); // store top-left corner
}

Point Circle::center() const
{
    return Point(point(0).x + r, point(0).y + r);
}

void Circle::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
}

void Ellipse::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
}

void Text::draw_lines() const
{
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(), fnt_sz);
    fl_draw(lab.c_str(), point(0).x, point(0).y);
    fl_font(ofnt, osz);
}

Axis::Axis(Orientation d, Point xy, int length, int n, std::string lab) :
    label(Point(0, 0), lab)
{
    if (length < 0)
        error("bad axis length");

    switch (d)
    {
        case Axis::x:
            {
                Shape::add(xy); // axis line
                Shape::add(Point(xy.x + length, xy.y));

                if (1 < n) // add notches
                {
                    int dist = length / n;
                    int x = xy.x + dist;

                    for (int i = 0; i < n; i++)
                    {
                        notches.add(Point(x, xy.y), Point(x, xy.y - 5));
                        x += dist;
                    }
                }

                // label under line
                label.move(length / 3, xy.y + 20);
                break;
            }
        case Axis::y:
            {
                Shape::add(xy); // y axis goes up
                Shape::add(Point(xy.x, xy.y - length));

                if (1 < n) // add notches
                {
                    int dist = length / n;
                    int y = xy.y - dist;

                    for (int i = 0; i < n; i++)
                    {
                        notches.add(Point(xy.x, y), Point(xy.x + 5, y));
                        y -= dist;
                    }
                }

                // label at top
                label.move(xy.x - 10, xy.y - length - 10);
                break;
            }
        case Axis::z:
            error("z axis not implemented");
    }
}

void Axis::draw_lines() const
{
    Shape::draw_lines();
    notches.draw(); // notches may have a different color than line
    label.draw(); // label may have different color than line
}

void Axis::set_color(Color c)
{
    Shape::set_color(c);
    notches.set_color(c);
    label.set_color(c);
}

void Axis::move(int dx, int dy)
{
    Shape::move(dx, dy);
    notches.move(dx, dy);
    label.move(dx, dy);
}

// graph f(x) for x in [r1:r2) using count line segments with (0,0)
// displayed at xy. x-coords are scaled by xscale, and y-coords by yscale
Function::Function(Fct f, double r1, double r2, Point xy, int count,
                   double xscale, double yscale)
{
    if (r2 - r1 <= 0)
        error("bad graphing range");

    if (count <= 0)
        error("non-positive graphing count");

    double dist = (r2 - r1) / count;
    double r = r1;

    for (int i = 0; i < count; i++)
    {
        add(Point(xy.x + int(r * xscale), xy.y - int(f(r) * yscale)));
        r += dist;
    }
}

// check if file name exists and can be opened for reading
bool can_open(const std::string& s)
{
    std::ifstream ff(s.c_str());
    return ff ? true : false;
}

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

Suffix::Encoding get_encoding(const std::string& s)
{
    struct SuffixMap {
        const char *extension;
        Suffix::Encoding suffix;
    };

    static SuffixMap smap[] = {
        {".jpg", Suffix::jpg}, {".jpeg", Suffix::jpg}, {".gif", Suffix::gif}
    };

    for (int i = 0, n = ARRAY_SIZE(smap); i < n; i++)
    {
        size_t len = strlen(smap[i].extension);

        if (s.length() >= len && s.substr(s.length() - len, len)
            == smap[i].extension)
            return smap[i].suffix;
    }

    return Suffix::none;
}

Image::Image(Point xy, std::string s, Suffix::Encoding e)
    : w(0), h(0), fn(xy, "")
{
    add(xy);

    if (!can_open(s))
    {
        fn.set_label("cannot open \"" + s + '\"');
        p = new Bad_image(30, 20); // error image
        return;
    }

    if (e == Suffix::none)
        e = get_encoding(s);

    // check if known encoding
    switch (e)
    {
        case Suffix::jpg:
            p = new Fl_JPEG_Image(s.c_str());
            break;
        case Suffix::gif:
            p = new Fl_GIF_Image(s.c_str());
            break;
        default: // unsupported image encoding
            fn.set_label("unsupported file type \"" + s + '\"');
            p = new Bad_image(30, 20); // error image
    }
}

void Image::draw_lines() const
{
    if (fn.label() != "")
        fn.draw_lines();

    if (w && h)
        p->draw(point(0).x, point(0).y, w, h, cx, cy);
    else
        p->draw(point(0).x, point(0).y);
}
}

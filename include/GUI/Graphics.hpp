#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <vector> // for vector
#include <string> // for string
#include <initializer_list> // for initializer_list
#include <utility> // for pair
#include <map> // for map
#include <cmath> // for sqrt()
#include <FL/fl_draw.H> // for Fl_Color, fl_color(), Fl_Font, fl_font()
#include <FL/Fl_Image.H> // for Fl_Image, draw_empty()
#include <GUI/Point.hpp> // for Point
#include <GUI/gui_facilities.hpp> // for error()

namespace Graphics_lib {

// typedef double Fct(double);
using Fct = double (*)(double);

// class that provides an abstraction that maps FLTK's Fl_Color to a Color_type
// and encapsulates the notion of transparency in terms of visibility and
// invisibility
// NOTE: Fl_Colors are unsigned ints
struct Color {
    // an abstraction for Fl_Colors that serves as a color palette
    enum Color_type {
        red = FL_RED,
        blue = FL_BLUE,
        green = FL_GREEN,
        yellow = FL_YELLOW,
        white = FL_WHITE,
        black = FL_BLACK,
        magenta = FL_MAGENTA,
        cyan = FL_CYAN,
        dark_red = FL_DARK_RED,
        dark_green = FL_DARK_GREEN,
        dark_yellow = FL_DARK_YELLOW,
        dark_blue = FL_DARK_BLUE,
        dark_magenta = FL_DARK_MAGENTA,
        dark_cyan = FL_DARK_CYAN
    };

    // provides a means to mark object as visible or invisible
    enum Transparency { invisible = 0, visible = 255 };

    // builds a Color by specifying a Color_type
    Color(Color_type ct)
        : c {Fl_Color {ct}},
          v {visible} {  }

    // builds a Color by specifying a visibility
    Color(Transparency vi)
        : c {Fl_Color()}, // default color
          v {vi} {  }

    // builds a Color by specifying a Color_type and visibility
    Color(Color_type ct, Transparency vi)
        : c {Fl_Color {ct}},
          v {vi} {  }

    // conversion constructor
    // builds a Color by specifying an unsigned int... that corresponds to a
    // Color_type
    Color(unsigned int ct)
        : c {Fl_Color {ct}},
          v {visible} {  }

    // returns this Color's Fl_color
    Fl_Color get_fl_color() const
    {
        return c;
    }

    // returns this Color's visibility
    char visibility() const
    {
        return v;
    }

    // sets this Color's Transparency/visibility to vi
    void set_visibility(Transparency vi)
    {
        v = vi;
    }

private:
    Fl_Color c; // this Color's Fl_color
    unsigned char v; // this Color's visibility
};

// a Line_style is a class that is used to describe the pattern used to outline
// a line
struct Line_style {
    // an abstraction for FLTK line styles
    enum Line_style_type {
        solid = FL_SOLID,               // ----
        dash = FL_DASH,                 // - - - -
        dot = FL_DOT,                   // ....
        dashdot = FL_DASHDOT,           // -.-.
        dashdotdot = FL_DASHDOTDOT      // -..-..
    };

    // builds a Line_style by specifying a Line_style_type
    Line_style(Line_style_type lst)
        : s {lst},
          w {0} {  }

    // builds a Line_style by specifying a Line_style_type and a width
    Line_style(Line_style_type lst, unsigned int wi)
        : s {lst},
          w {wi} {  }

    // conversion constructor
    // builds a Line_style by specifying an unsigned int that corresponds to a
    // Line_style_type
    Line_style(unsigned int lst)
        : s {lst},
          w {0} {  }

    // returns this Line_style's width
    unsigned int width() const
    {
        return w;
    }

    // returns this Line_style's Line_style_type
    unsigned int style() const
    {
        return s;
    }

private:
    unsigned int s; // this Line_style's Line_style_type
    unsigned int w; // this Line_style's width
};

// class that provides an abstraction for FLTK's FL_Font type
// NOTE: FL_fonts are ints
class Font {
public:
    // provides access to several predefined fonts through the class
    enum Font_type {
        helvetica = FL_HELVETICA,
        helvetica_bold = FL_HELVETICA_BOLD,
        helvetica_italic = FL_HELVETICA_ITALIC,
        helvetica_bold_italic = FL_HELVETICA_BOLD_ITALIC,
        courier = FL_COURIER,
        courier_bold = FL_COURIER_BOLD,
        courier_italic = FL_COURIER_ITALIC,
        courier_bold_italic = FL_COURIER_BOLD_ITALIC,
        times = FL_TIMES,
        times_bold = FL_TIMES_BOLD,
        times_italic = FL_TIMES_ITALIC,
        times_bold_italic = FL_TIMES_BOLD_ITALIC,
        symbol = FL_SYMBOL,
        screen = FL_SCREEN,
        screen_bold = FL_SCREEN_BOLD,
        zapf_dingbats = FL_ZAPF_DINGBATS
    };

    // builds a Font from a font_type
    Font(Font_type ft)
        : f {ft} {  }

    // conversion constructor
    // builds a Font from an int that corresponds to a Font_type
    Font(int ft)
        : f {ft} {  }

    // returns this Font's Fl_font
    Fl_Font get_fl_font() const
    {
        return f;
    }

private:
    int f; // this Font's Font_type
};

// class template that can be used to emulate a vector of references of any
// type
// NOTE:: if an object is passed to Vector_ref as a reference, it is assumed to
// be owned by the caller, who is responsible for its lifetime...
// HOWEVER, if an object is passed to Vector_ref as a pointer, it is assumed to
// have been allocated by new and it is Vector_ref's responsibility to delete
// it
template<class T>
class Vector_ref {
    // NOTE: every element stored by this Vector_ref is stored as a pointer and
    // has reference semantics
    std::vector<T*> v; // caller manages these
    std::vector<T*> owned; // these need to be deleted

public:
    // builds an empty Vector_ref
    Vector_ref() = default;

    // builds a Vector_ref that contains a single element
    Vector_ref(T& a)
    {
        push_back(a); // calls appropriate push_back() method below
    }

    // Vector_ref(T& a, T& b);

    // Vector_ref(T& a, T& b, T& c);

    // builds a Vector_ref that contains up to four elements
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
        // calls appropriate push_back method below for each object
        if (a)
            push_back(a);
        if (b)
            push_back(b);
        if (c)
            push_back(c);
        if (d)
            push_back(d);
    }

    // destructor... deletes every object passed to this Vector_ref as a
    // pointer
    ~Vector_ref()
    {
        for (size_t i = 0; i < owned.size(); i++)
            delete owned[i];
    }

    // adds a named object to this Vector_ref
    void push_back(T& named)
    {
        v.push_back(&named);
    }

    // adds an unnamed object to this Vector_ref
    void push_back(T* unnamed)
    {
        v.push_back(unnamed);
        owned.push_back(unnamed);
    }

    // read access to this Vector_ref... returns the ith element in this
    // Vector_ref
    T& operator[](size_t i)
    {
        return *v[i];
    }

    // read access to this Vector_ref for constant Vector_refs... returns the
    // ith element in this Vector_ref
    T const& operator[](size_t i) const
    {
        return *v[i];
    }

    // returns the number of elements in this Vector_ref
    size_t size() const
    {
        return v.size();
    }
};

// the Shapes class serves as a base class only... it's  an abstract base class
// that provides methods that deal with color and style, and hold sequences of
// lines
class Shape {
public:
    // applies style and color and calls draw_lines()...
    // serves as a wrapper for various FLTK functions to set the color and
    // style to this Shape's specifics while the call to draw_lines() does the
    // actual drawing
    void draw() const; // deals with color and draws lines

    // moves every Point's x component by dx and y component by dy in this
    // Shape's vector of Points
    virtual void move(int dx, int dy); // move shape += dx and += dy

    // sets this Shape's Color to col
    void set_color(Color col)
    {
        lcolor = col;
    }

    // returns this Shape's color
    Color color() const
    {
        return lcolor;
    }

    // sets this Shape's Line_style to sty
    void set_style(Line_style lsty)
    {
        ls = lsty;
    }

    // returns this Shape's Line_style
    Line_style style() const
    {
        return ls;
    }

    // sets this Shape's fill Color to col
    void set_fill_color(Color col)
    {
        fcolor = col;
    }

    // returns this Shape's fill Color
    Color fill_color() const
    {
        return fcolor;
    }

    // returns the ith Point in this Shape's vector of Points
    Point point(size_t i) const
    {
        return points[i]; // read only access to points
    }

    // returns the number of points in this Shape's vector of Points
    size_t number_of_points() const
    {
        return points.size();
    }

    // NOTE: marking a memeber function as "= delete" means that it will not
    // be generated by the compiler and that any attempts to use the function
    // will result in a compilation error
    // disable Shape's copy constructor
    Shape(Shape const&) = delete;

    // disable Shape's copy-assignment operator
    Shape& operator=(Shape const&) = delete;

    // ensures calls to a Shape's destructor invoke the destructor of an
    // appropriately derived shape
    virtual ~Shape() {  }

protected: // accessible only to derived classes
    // NOTE: making Shape's constructors protected ensures that Shape serves
    // as an abstract base class
    // Shape() { }
    Shape() = default;

    // initilizier list constructor... builds a Shape by adding the Points
    // passed to pts to this Shape's vector of Points
    Shape(std::initializer_list<Point> pts)
    {
        for (auto p : pts)
            add(p);
    }

    virtual void draw_lines() const; // draws appropriate lines

    // enables derived classes to add Point p to this Shape's vector of
    // Points (points)
    void add(Point p) // add p to points
    {
        points.push_back(p);
    }

    // sets the ith Point in this Shape's vector of Points to p
    void set_point(size_t i, Point p) // points[i] = p
    {
        points[i] = p;
    }

private:
    std::vector<Point> points; // not used by all shapes

    // default color for lines and characters
    // NOTE: the call to fl_color() with no arguments returns the last Fl_Color
    // set by a call to fl_color(Fl_color)
    Color lcolor {fl_color()}; // color for lines and characters

    // line style
    Line_style ls {0};

    // fill color
    Color fcolor {Color::invisible}; // fill color
};

// a Function is a shape that graphs the function y=f(x) in the range [r1:r2)
// with its origin at the Point orig using count line segments scaled by
// x_scale and y_scale in the horizontal and vertical directions, respectively
// NOTE: Fct f is pointer to a function that takes a double and returns a
// double
struct Function : Shape {
    // NOTE: function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig, int count = 100,
             double x_scale = 25., double y_scale = 25.);
};

// a Line is a shape defined by 2 points
struct Line : Shape {
    // builds a Line from two Points
    Line(Point p1, Point p2)
    {
        add(p1); // add p1 to this Line
        add(p2); // add p2 to this Line
    }
};

// a Rectangle is a Shape that can be defined in terms of an upper left corner,
// a width, and a height, or an upper left corner and an lower right corner
struct Rectangle : Shape {
    // builds a rectangle by specifying the top-left Point and a width and a
    // height
    Rectangle(Point xy, int wi, int hi)
        : w {wi},
          h {hi}
    {
        // add Point xy (upper left) to this Rectangle if its height and width
        // are valid
        if (h <= 0 || w <= 0)
            error("Bad rectangle: non-positive side");

        add(xy);
    }

    // builds a rectangle by sepcifying an upper left and lower-right point
    Rectangle(Point x, Point y)
        : w {y.x - x.x},
          h {y.y - x.y}
    {
        // add Point x (upper left) to this Rectangle if its height and width
        // are valid
        if (h <= 0 || w <= 0)
            error("Bad rectangle: non-positive width or height");

        add(x);
    }

    // draws and possibly fill this Rectangle
    void draw_lines() const;

    // returns this Rectangle's height
    int height() const
    {
        return h;
    }

    // returns this Rectangle's width
    int width() const
    {
        return w;
    }

private:
    int w; // this Rectangle's width
    int h; // this Rectangle's height
};

// an Open_polyline is a Shape that is composed of a series of connected Line
// segments defined by a series of Points
struct Open_polyline : Shape {
    // using Shape::Shape; // use Shape's constructors

    Open_polyline() = default;

    // builds an Open_polyline from a list of Points
    Open_polyline(std::initializer_list<Point> pts)
        : Shape {pts} {  }

    // adds a Point to this Open_polyline
    void add(Point p)
    {
        Shape::add(p);
    }

    // draws this Open_polyline provided that its line Color is visible... also
    // fills this Open_polyline provided that its fill Color is visible
    void draw_lines() const;
};

// a Closed_polyline is an Open_polyine that is composed of a closed series of
// connected Line segments
struct Closed_polyline : Open_polyline {
    using Open_polyline::Open_polyline;

    // draws this Closed_polyline provided it contains more than two points and
    // its line Color is visible... also fills this Closed_polyline provided
    // its fill Color is visible
    void draw_lines() const;
};

// a Polygon is a closed sequence of non-intersecting lines
struct Polygon : Closed_polyline {
    // use Closed_polyline's constructors
    using Closed_polyline::Closed_polyline;

    // adds Point p to this Polygon
    void add(Point p);

    // draws and possibly fill this Polygon provided it consists of at least
    // three points
    void draw_lines() const;
};

// a Lines object is Shape that represents a collection of Lines
struct Lines : Shape {
    // default constructor
    // builds an empty Lines object
    Lines() = default;

    // initializer list constructor... builds a Lines object from a list of
    // lines derived from pairs of Points
    Lines(std::initializer_list<std::pair<Point, Point>> lines)
    {
        for (auto pts : lines)
            add(pts.first, pts.second);
    }

    // draws the Lines added to this Lines object with add() by connecting each
    // pair of Points provided that this Lines object is visible
    void draw_lines() const;

    // add a Line defined by two Points to this Lines object
    void add(Point p1, Point p2)
    {
        Shape::add(p1);
        Shape::add(p2);
    }
};

// a Text object is a Shape that represents a line of text starting at a Point
// used to represent the lower-leftmost corner of the line
struct Text : Shape {
    // builds a Text object that contains s and begins at x (lower-left) using
    // the default Font and font size
    Text(Point x, std::string const& s)
        : lab {s} // , fnt {fl_font()}, fnt_sz {15}
    {
        add(x);
    }

    // draws this Text object's string label/contents
    void draw_lines() const;

    // sets this Text object's label (contents) to s
    void set_label(std::string const& s)
    {
        lab = s;
    }

    // returns this Text object's label string (contents)
    std::string label() const
    {
        return lab;
    }

    // sets this Text object's Font to f
    void set_font(Font f)
    {
        fnt = f;
    }

    // returns this Text object's Font
    Font font() const
    {
        return fnt;
    }

    // sets this Text object's font size of s
    void set_font_size(int s)
    {
        fnt_sz = s;
    }

    // returns this Text object's font size
    int font_size() const
    {
        return fnt_sz;
    }

private:
    std::string lab; // this Text object's label string/contents
    Font fnt {fl_font()}; // this Text object's Font
    // this Text object's font size
    int fnt_sz {(fl_size() < 14) ? 14 : fl_size()};
};

// an Axis is a Shape that consists of a line, a number of notches on that
// line and a Text label
struct Axis : Shape {
    // axes of Orientation
    enum Orientation { x, y , z };

    // builds an Axis with Orientation d starting at xy extending for length
    // pixels with num_notches notches and the label lab
    Axis(Orientation d, Point xy, int length, int num_notches = 0,
         std::string label = "");

    // draws this Axis
    void draw_lines() const;

    // moves this Axis's primary line, notches, and label by dx points in the
    // x direction and dy points in the y direction
    void move(int dx, int dy)
    {
        Shape::move(dx, dy); // move this Axis's primary line
        notches.move(dx, dy); // move this Axis's notches
        label.move(dx, dy); // move this Axis's label
    }
    
    // sets this Axis's primary line color, notch color, and label color to c
    void set_color(Color c)
    {
        Shape::set_color(c); // set this Axis's primary line color
        notches.set_color(c); // set this Axis's notches color
        label.set_color(c); // set this Axis's label color
    }

    Text label; // this Axis's label
    Lines notches; // this Axis's notches
};

// a Circle is a Shape that's defined by a central Point and a radius
struct Circle : Shape {
    // builds a Circle by by specifying a center Point and a radius
    Circle(Point p, int rd)
        : r {rd}
    {
        // store a Point that can be used to represent the upper left corner
        // of a bounding box for this Circle
        add({p.x - r, p.y - r});
    }

    // draws this Circle if it is visible
    void draw_lines() const;

    // returns the Point at the center of this Circle
    Point center() const
    {
        // NOTE: remember to add the raidus to this Circle's Point... since the
        // Point we stored corresponds to the upper left corner of a box to
        // bound this Circle
        return {point(0).x + r, point(0).y + r};
    }

    // returns this Circle's radius
    int radius() const
    {
        return r;
    }

    // sets this Circle's radius to rd and updates the center of this Circle
    // relative to rd
    void set_radius(int rd)
    {
        // maintain center
        set_point(0, {center().x - rd, center().y - rd});
        r = rd;
    }

private:
    int r; // this Circle's radius
};

// an Ellipse is a circular Shape that is defined in terms of a central Point
// and a distance from its center on the x-axis and a distance from its center
// on the y-axis
struct Ellipse : Shape {
    // builds an Ellipse by specifying a center Point, a distance from the
    // center on the x axis (wi), and a distance from the center on the
    // y axis (hi)
    Ellipse(Point p, int wi, int hi)
        : w {wi},
          h {hi}
    {
        // store a Point that can be used to represent the upper left corner
        // of a bounding box for this Ellipse
        add({p.x - w, p.y - h});
    }

    // draws this Ellipse if it is visible
    void draw_lines() const;

    // returns a Point at the center of this Ellipse
    Point center() const
    {
        // NOTE: remember to add the x and y offsets to this Ellipse's Point...
        // since the Point we stored corresponds to the upper left corner of a
        // box to bound this Ellipse
        return {point(0).x + w, point(0).y + h}; // matches Shape's point()
    }

    // returns the focus of this Ellipse with respect to the positive x or y
    // axis
    Point focus1() const
    {
        if (h <= w)  // foci on x axis
            return {center().x + int(sqrt(double(w * w - h * h))), center().y};
        else // foci on y axis
            return {center().x, center().y + int(sqrt(double(h * h - w * w)))};
    }

    // returns the focus of this Ellipse with respect to the negative x or y
    // axis
    Point focus2() const
    {
        if (h <= w)  // foci on x axis
            return {center().x - int(sqrt(double(w * w - h * h))), center().y};
        else  // foci on y axis
            return {center().x, center().y - int(sqrt(double(h * h - w * w)))};
    }

    // sets this Ellipse's major axis to ww and updates the center of this
    // Ellipse relative to wi
    void set_major(int wi)
    {
        set_point(0, {center().x - wi, center().y - h});
        w = wi;
    }

    // returns this Ellipse's major axis
    int major() const
    {
        return w;
    }

    // sets this Ellipse's minor axis to hi and updates the center of this
    // Ellipse relative to hi
    void set_minor(int hi)
    {
        set_point(0, {center().x - w, center().y - hi});
        h = hi;
    }

    // returns this Ellipse's minor axis
    int minor() const
    {
        return h;
    }

private:
    int w; // this Ellipse's major axis
    int h; // this Ellipse's minor axis
};

// a Marked_polyline is an Open_polyline that is used to provided labels to
// points on a graph
struct Marked_polyline : Open_polyline {
    // builds a Marked_polyline from a string (mark)
    // NOTE: if m is empty, then the default mark for this Marked_polyline
    // will be "*"
    Marked_polyline(std::string const& m)
        : mark {m}
    {
        if (m == "")
            mark = "*";
    }

    // builds a Marked_polyline from a string of marks and a list of Points
    // NOTE: if m is empty, then the default mark for this Marked_polyline
    // will be "*"
    Marked_polyline(std::string const& m, std::initializer_list<Point> pts)
        : Open_polyline {pts},
          mark {m}
    {
        if (m == "")
            mark = "*";
    }

    // draws this Marked_polyline
    void draw_lines() const;

private:
    std::string mark; // this Marked_polyline's mark(s)
};

// a Marks object is a Marked_polyline object whose line is invisible
struct Marks : Marked_polyline {
    // builds a Marks object from a string (mark)
    Marks(std::string const& m)
        : Marked_polyline {m}
    {
        set_color(Color::invisible);
    }

    // builds a Marks object from a string of marks and a list of Points
    Marks(std::string const& m, std::initializer_list<Point> pts)
        : Marked_polyline {m, pts}
    {
        set_color(Color::invisible);
    }
};

// a Mark is a Marks object that is comprised of a single Point and a mark
struct Mark : Marks {
    // builds a Mark at a Point xy with label c
    Mark(Point xy, char c)
        : Marks {std::string(1, c)}
    {
        add(xy);
    }
};

// class that provides an enum that represents the file extensions associated
// with common image storage formats
struct Suffix {
    enum Encoding { none, jpg, gif };
};

// provides a mapping between commonly used file extensions for images and
// their encoding type
const std::map<std::string, Suffix::Encoding> SuffixMap {
    {".jpg", Suffix::jpg}, {".jpeg", Suffix::jpg}, {".gif", Suffix::gif}};

// returns the Encoding associated with s
Suffix::Encoding get_encoding(std::string const& s);

// an Image is a Shape defined by a Point that corresponds to its upper left,
// a file name (path), and an Encoding Suffix
struct Image : Shape {
    // builds an Image with an upper left corner at xy, stored at the path
    // file_name, and with an optional suffix
    Image(Point xy, std::string file_name, Suffix::Encoding e = Suffix::none);

    // destructor
    ~Image()
    {
        delete p;
    }

    // draws this image
    void draw_lines() const;

    // selects a wi by hi sub-picture of this Image to be displayed with its
    // upper left corner at this Image's Point xy
    void set_mask(Point xy, int wi, int hi)
    {
        w = wi;
        h = hi;
        cx = xy.x;
        cy = xy.y;
    }

private:
    // define masking box within image relative to position (cx, cy)
    int w; // width of mask
    int h; // height of mask
    int cx; // upper left x coordinate
    int cy; // upper left y coordinate
    Fl_Image *p; // FLTK object that hold's this Image's image data
    Text fn; // this Image's Text label
};

// a Bad_image is an Fl_image that is used as a placeholder in the event that
// the construction of an Image fails
struct Bad_image : Fl_Image {
    // builds an empty image with width w and height h
    Bad_image(int h, int w)
        : Fl_Image {h, w, 0} {  }

    // draws and empty box with an upper left coordinate at (x, y)
    void draw(int x, int y, int, int, int, int)
    {
        draw_empty(x, y);
    }
};

}
#endif

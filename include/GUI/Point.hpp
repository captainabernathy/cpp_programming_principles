#ifndef POINT_HPP
#define POINT_HPP

// only defined when performing I/O operations on Points is needed
#ifdef POINT_IO
#include <istream> // for istream
#include <stdexcept> // for runtime_error
#include <ostream> // for ostream
#endif

// class that represents a Point as two integers: x and y
struct Point {
    int x; // this Point's x coordinate
    int y; // this Point's y coordinate
    
    // default constructor... initializes this Point to (0,0)
    // Point() = default;

    // initializes this Point's x coordinate to xi and y coordinate to yi
    Point(int xi = 0, int yi = 0)
        : x {xi},
          y {yi} {  }
};

// overloaded equality operator for two points...
// returns true when both a and b have the same corresponding x and y values,
// false otherwise
inline bool operator==(Point a, Point b)
{
    return (a.x == b.x) && (a.y == b.y);
}

// overloaded inequality operator for two points
// returns true when a and b do not have the same corresponding x and y values,
// false otherwise
inline bool operator!=(Point a, Point b)
{
    return !(a == b);
}

// only defined when performing I/O operations on Points is needed
#ifdef POINT_IO
// overloaded input operator for a Point
// function reads a formated Point "(x,y)" into an input stream
std::istream& operator>>(std::istream& ist, Point& p)
{
    char a; // '('
    char b; // ','
    char c; // ')'

    if ((ist >> a >> p.x >> b >> p.y >> c)
        && !(a == '(' && b == ',' && c == ')'))
        throw std::runtime_error("Invalid format");

    return ist;
}

// overloaded output operator for a Point
// function formats and writes a Point "(x,y)" to an output stream
std::ostream& operator<<(std::ostream& ost, Point const& p)
{
    return ost << '(' << p.x << ',' << p.y << ')';
}
#endif

#endif

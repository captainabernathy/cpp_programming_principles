#ifndef POINT_HPP
#define POINT_HPP

// class that represents a Point as two integers: x and y
struct Point {
    int x; // this Point's x coordinate
    int y; // this Point's y coordinate

    // initializes this Point's x coordinate to xi and y coordinate to yi
    Point(int xi = 0, int yi = 0)
        : x {xi},
          y {yi} {  }

    // default constructor... initializes this Point to (0, 0)
    Point() = default;
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

#endif

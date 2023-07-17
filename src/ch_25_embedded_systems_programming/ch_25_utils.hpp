#ifndef CH_25_UTILS_HPP
#define CH_25_UTILS_HPP

// some dummy class hierarchy to use with chapter examples

#include <iostream> // for cout

// the Point class is just filler to make Shapes with different layouts
class Point {
public:
    Point(int xi, int yj)
        : x {xi}, y {yj} {  }
private:
    int x;
    int y;
};

// a Shape is just a dummy class
class Shape {
public:
    virtual void draw()
    {
        std::cout << "Shape's draw()\n";
    }

    virtual ~Shape() {  };
};

// a Circle is a Shape... that has a different layout that a Shape
class Circle : public Shape {
public:
    Circle(Point const& center = {0, 0}, int radius = 0)
        : c {center}, rad {radius} {  }

    void draw()
    {
        std::cout << "Circle's draw()\n";
    }

private:
    Point c;
    int rad;
};

// a Rectangle is a Shape... that has a different layout than a Shape
class Rectangle : public Shape {
public:
    Rectangle(Point const& up_left = {0, 0}, Point const& low_right = {0, 0})
        : ul {up_left}, lr {low_right} {  }

    void draw()
    {
        std::cout << "Rectangle's draw()\n";
    }

private:
    Point ul;
    Point lr;
};

// a Polygon is a Shape... that has the same layout as a Shape
class Polygon : public Shape {
public:
    void draw()
    {
        std::cout << "Polygon's draw()\n";
    }
};

#endif

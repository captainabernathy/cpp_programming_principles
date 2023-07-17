// program demonstrates many of the problems than can occur when passing
// an array of objects as a pointer

#include <vector> // for vector
#include <iostream> // for cout
#include "ch_25_utils.hpp" // for Shape, Circle, Polygon, Rectangle

// function that accepts an array that contains sz Shapes via the pointer s and
// calls each Shape's draw() method
void poor(Shape *s, size_t sz);

// function that demonstrates how many of the problems associated with passing
// an array as a pointer can occur
void f(Shape *q, size_t nshapes, std::vector<Circle>& s0);

int main()
{
    using std::vector;

    Polygon p1[5]; // array of 5 Polygons

    vector<Circle> vc(5); // vector of 5 Circles

    // initialize Polygons and Circles
    for (size_t i = 0; i < 5; i++)
    {
        vc[i] = Circle({1, 2}, 3);
        p1[i] = Polygon();
    }

    f(p1, 5, vc); // bad things might happen

    return 0;
}

// function that accepts an array that contains sz Shapes via the pointer s and
// calls each Shape's draw() method
void poor(Shape *s, size_t sz)
{
    for (size_t i = 0; i < sz; i++)
        s[i].draw();
}

// function that demonstrates how many of the problems associated with passing
// an array as a pointer can occur
void f(Shape *q, size_t nshapes, std::vector<Circle>& s0)
{
    // NOTE: if s[0] is empty then &s[0] is an error... also if crashes
    // if sizeof(Circle) != sizeof(Shape)
    // poor(&s0[0], s0.size()); // ERROR... since sizeof(Circle) > sizeof(Shape)
    // std::cout << '\n';

    Shape sc[s0.size()];
    for (size_t i = 0; i < s0.size(); i++)
        sc[i] = s0[i]; // beware... possible slicing
 
    // sc index-able as an array now... but calls Shape's draw() instead of
    // Circle's... would crash if sc were and array of Circles
    poor(sc, s0.size());
    std::cout << '\n';

    const int max = 5;
    Polygon s1[max]; // only works bc sizeof(Polygon) == sizeof(Shape)
    Shape s2[max];
    for (size_t i = 0; i < max; i++)
    {
        s1[i] = Polygon(); // beware... possible slicing
        s2[i] = Rectangle({1,1}, {2,2}); // beware... possible slicing
    }

    // could be bad if s1 is uninitialized or has less than max elements
    // calls Polygon's draw() only bc sizeof(Polygon) == sizeof(Shape)
    poor(s1, max);
    std::cout << '\n';

    // could be bad if s2 is uninitialized or has less than max elements
    // calls Shape's draw()... would crash if s2 were an array of Rectangles
    poor(s2, max);
    std::cout << '\n';

    Shape *p1 = new Rectangle({0, 0}, {10, 20});
    Shape *p2 = new Rectangle({0, 0}, {11, 21});
    Shape arr[2] = {*p1, *p2};

    poor(p1, 1); // OK for a single element... calls Rectangle's draw
    std::cout << '\n';

    poor(p2, 1); // OK for a single element... calls Rectangle's draw
    std::cout << '\n';

    // calls Shape's draw()... would crash if arr were an array of Rectangles
    poor(arr, 2);
    std::cout << '\n';

    // could be bad if q is uninitialized or has less than nshapes elements
    // NOTE: will crash if the sizeof(q[i]) != sizeof(Shape)
    poor(q, nshapes);

    delete p1;
    p1 = nullptr;
    delete p2;
    p2 = nullptr;
}

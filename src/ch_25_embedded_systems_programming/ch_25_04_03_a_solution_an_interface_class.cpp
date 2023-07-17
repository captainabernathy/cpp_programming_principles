// program demonstrates how the Array_ref<> template can be used to avoid
// many of the problems that can occur when passing an array of objects as a
// pointer

#include <vector> // for vector
#include <iostream> // for cout

// so that the Array_ref class used by this program does not include an
// overloaded call operator
#ifndef NO_ARRAY_REF_CALL_OPERATOR
#define NO_ARRAY_REF_CALL_OPERATOR
#endif

#include <array_ref_utils/array_ref_utils.hpp> // for Array_ref<>, make_ref<>()
#include "ch_25_utils.hpp" // for Shape, Circle, Polygon, Rectangle

// function that accepts an Array_ref<> of Shapes and calls each Shape's draw()
// method
//
// NOTE: a is an Array_ref<> of Shapes (a container that holds Shapes)
void better(Array_ref<Shape> a);

// function that demonstrates how to use the Array_ref<> template to avoid
// many of the problems associated with passing an array as pointer
//
// NOTE: q is a pointer to an array of Shapes
// nshapes is the number of Shapes in q
// s0 is a reference to a vector of Circles
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

    f(p1, 5, vc); // uses Array_ref<> to avoid bad things

    return 0;
}

// function that accepts an Array_ref<> of Shapes and calls each Shape's draw()
// method
void better(Array_ref<Shape> a)
{
    for (size_t i = 0; i < a.size(); i++)
            a[i].draw();
}

// function that demonstrates how to use the Array_ref<> template to avoid
// many of the problems associated with passing an array as pointer
void f(Shape *q, size_t nshapes, std::vector<Circle>& s0)
{
    // NOTE: no conversion from Array_ref<Circle> to Array_ref<Shape>
    // better(make_ref(s0)); // ERROR!!!

    // so... make a vector of Shapes and add each Circle in s0 to it
    std::vector<Shape> sv1;
    for (auto const& c : s0)
        sv1.push_back(c);

    // make_ref(sv1) calls make_ref(vector<T>&v) and returns Array_ref<Shape>
    better(make_ref(sv1));
    std::cout << '\n';

    const int max = 5;
    Polygon s1[max]; // 5 element array of pointers to Polygons

    for (size_t i = 0; i < max; i++)
        s1[i] = Polygon();

    // NOTE: no conversion form Array_ref<Polygon> to Array_ref<Shape>
    // better(make_ref(s1)); // ERROR!!!

    // so...  create a pointer to the array and create an Array_ref of max
    // pointers from it
    Shape *sp = s1;

    // make_ref(sp,max) calls make_ref(T *p,size_t s) and
    // returns Array_ref<Shape>
    better(make_ref(sp, max));
    std::cout << '\n';

    Shape s2[max]; // 5 element array of pointers to Shapes

    for (size_t i = 0; i < max; i++)
        s2[i] = Circle({1, 2}, 3);

    // make_ref(s1) calls make_ref(T (&p)[N]) and returns Array_ref<Shape>
    better(make_ref(s2)); // OK
    std::cout << '\n';
    
    // a pointer to a shape
    Shape *p1 = new Rectangle {{0, 0}, {10, 20}};
    
    // make_ref(p1,1) calls make_ref(T *p, size_t s)
    better(make_ref(p1, 1)); // OK
    std::cout << '\n';

    // make_ref(q,nshapes) calls make_ref(T *p, size_t s) and returns
    // Array_ref<Shape>
    better(make_ref(q, nshapes));
    std::cout << '\n';

    delete p1;
    p1 = nullptr;
    better(make_ref(p1, 1)); // NOTE: ONLY OK if p1 is NULL... this is brittle
}

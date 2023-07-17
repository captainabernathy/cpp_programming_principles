#include <array_ref_utils/array_ref_utils.hpp> // for Array_ref<>, make_ref<>()
#include "ch_25_utils.hpp" // for Shape, Circle, Polygon, Rectangle
#include <vector> // for vector
#include <iostream> // for cout

// function that accepts a constant Array_ref<> of constant pointers to Shapes
// and calls each Shape's draw() method
//
// NOTE: a is a constant Array_ref<> of constant pointers to Shapes... a
// container that holds pointers
void better2(const Array_ref<Shape *const> a);

// function that demonstrates how to use the Array_ref<> template and
// conversion operator to more effectively avoid many of the problems
// associated with passing an array as pointer
//
// NOTE: q is a pointer to a Shape
// nshapes is the number of Shapes in q
// s0 is a reference to a vector of pointers to Circles
void f(Shape *q, size_t nshapes, std::vector<Circle *>& s0);

int main()
{
    using std::vector;

    Polygon p1[5]; // array of 5 Polygons

    vector<Circle *> vc(5); // vector of 5 Circles

    // initialize Polygons and Circles
    for (size_t i = 0; i < 5; i++)
    {
        vc[i] = new Circle({1, 2}, 3);
        p1[i] = Polygon();
    }

    // uses Array_ref<> and conversion operator to avoid bad things
    f(p1, 5, vc);

    // deallocate Circles
    for (size_t i = 0; i < 5; i++)
    {
        delete vc[i];
        vc[i] = nullptr;
    }

    return 0;
}

// function that accepts a constant Array_ref<> of constant pointers to Shapes
// and calls each Shape's draw() method
void better2(const Array_ref<Shape* const> a)
{
    for (size_t i = 0; i < a.size(); i++)
        if (a[i])
            a[i]->draw();
}

// function that demonstrates how to use the Array_ref<> template and
// conversion operator to more effectively avoid many of the problems
// associated with passing an array as pointer
void f(Shape *q, size_t nshapes, std::vector<Circle *>& s0)
{
    // make_ref(s0) calls make_ref(vector<T>&) and returns Array_ref<Circle *>
    // better2(^^^) converts Array_ref<Circle *> to Array_ref<Shape* const>
    better2(make_ref(s0));
    std::cout << '\n';

    const int max = 5;
    Polygon *s1[max]; // 5 element array of pointers to Polygons

    for (size_t i = 0; i < max; i++)
        s1[i] = new Polygon();

    // make_ref(s1) calls make_ref(T (&p)[N]) and returns Array_ref<Polygon *>
    // better2(^^^) converts Array_ref<Polygon *> to Array_ref<Shape* const>
    better2(make_ref(s1));
    std::cout << '\n';

    Shape *s2[max]; // 5 element array of pointers to Shapes

    for (size_t i = 0; i < max; i++)
        s2[i] = new Circle({1, 2}, 3);

    // make_ref(s1) calls make_ref(T (&p)[N]) and returns Array_ref<Circle *>
    // better2(^^^) converts Array_ref<Circle *> to Array_ref<Shape* const>
    better2(make_ref(s2));
    std::cout << '\n';
    
    // a pointer to a shape
    Shape *p1 = new Rectangle {{0, 0}, {10, 20}};

    // NOTE: better2 expects a container of pointers
    // better2(make_ref(p1, 1)); // ERROR!!!

    // so create a container of pointers that contains p1
    Shape *s3[1];
    s3[0] = p1;

    // make_ref(s3,1) calls make_ref(T *p,size_t s) and returns
    // Array_ref<Shape *>
    // better2(^^^) converts Array_ref<Shape *> to Array_ref<Shape* const>
    better2(make_ref(s3, 1));
    std::cout << '\n';
   
    // NOTE: better2 expects a container of pointers
    // better2(make_ref(q, nshapes));

    // so create a container of nshapes pointers that contains pointers to
    // each Shape in q
    Shape *s4[nshapes];
    for (size_t i = 0; i < nshapes; i++)
    {
        s4[i] = &q[i];
    }

    // make_ref(s4,nshapes) calls make_ref(T *p,size_t s) and
    // returns Array_ref<Shape *>
    // better2(^^^) converts Array_ref<Shape *> to Array_ref<Shape* const>
    better2(make_ref(s4, nshapes));

    for (size_t i = 0; i < max; i++)
    {
        delete s1[i];
        s1[i] = nullptr;
        delete s2[i];
        s2[i] = nullptr;
    }

    delete p1;
    p1 = nullptr;
}

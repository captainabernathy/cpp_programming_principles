// program tests the implementation of a vector class that stores elements of
// type double, which now supports a move constructor and a move assignment
// operator
//
// vector (class)
//      vector()
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      vector(vector&& a)
//      vector& operator=(vector const& v)
//      vector& operator=(vector&& a)
//      ~vector()

#include <iostream> // for cout
#include "vector_dbl.hpp" // for vector

// function that returns the vector it receives... contrived example to
// demonstrate move assignment when u = f(v)
inline vector f(vector& v)
{
    return v;
}

// function that returns the vector it receives... contrived example to
// demonstrate copy assignment when u = g(v)
inline vector& g(vector& v)
{
    return v;
}

int main()
{
    // build a vector from an initializer list
    vector v1 {1.1, 2.2, 3.3};
    
    // build vector via copy constructor
    vector v2(v1);

    // build vector via default constructor
    vector v3;
    // update vector via copy assignment
    v3 = v2;
    
    // build vector via move constructor... explicty (for example)
    vector v4(std::move(v3));

    // build vector via default constructor
    vector v5;
    // update vector via move assignment... explicitly (for example)
    v5 = std::move(v4);

    // build vector via default constructor
    vector v6;
    v6 = f(v5); // move assignment
   
    v2 = g(v3); // copy assignment

    return 0;
}

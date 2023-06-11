// program tests the implementation of a vector class that stores elements of
// type double, which now supports a member access operator that provides read
// and write access to an element
//
// it also provides an overloaded implementation of the member access operator
// that facilitates read access to an element of a constant vector.
//
// vector (class)
//      vector(initializer_list<double> lst)
//      double& operator[](size_t n)
//      double operator[](size_t n) const
//      ~vector()
//
// void print_vector(vector const&, string const&)

#include <iostream> // for cout
#include "vector_dbl_utils.hpp" // for vector, print_vector()

// tester function for const and non-const overloaded member access operators
void f(vector const& cv, vector& v);

int main()
{
    using std::cout;

    // initialize vectors
    vector v1 {1.1, 2.2, 3.3};
    vector v2 {4.4, 5.5, 6.6};

    // output vectors
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");
    cout << '\n';

    // test overloaded member access operator
    f(v1, v2);

    // output results
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");

    return 0;
}

void f(vector const& cv, vector& v)
{
    double d = cv[1]; // ok to read from cv
    v[1] = v[2];  // ok to write to v
    v[2] = d;
}

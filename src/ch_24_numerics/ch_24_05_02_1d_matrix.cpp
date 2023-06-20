// program demonstrates how to perform various operations on a one-dimensonal
// Matrix using the class template Matrix<T,1> and other features provided
// by the numeric_utils library

#include <iostream> // for cout
#include <cmath> // for abs()
#include <numeric_utils/matrix_utils.hpp> // for Matrix<>, apply<>(),
                                          // scale_and_add<>(), dot_product<>()

// squares a in place
inline void square_in_place(int& a)
{
    a *= a;
}

// returns a squared
inline double square_d(double a)
{
    return a * a;
}

// scales a by b in place
inline void f2(int& a, int b)
{
    a *= b;
}

// returns the result of a * b
inline int scale(int a, int b)
{
    return a * b;
}

// scales d by s in place
inline void scale_in_place(double& d, double s)
{
    d *= s;
}

int main()
{
    using std::cout;
    using namespace Numeric_lib;

    Matrix<int, 1> a1(8); // 1D Matrix of ints
    Matrix<int> a(8); // matches Matrix<T,1> constructor

    cout << a1.size() << '\n'; // 8
    cout << a1.dim1() << "\n\n"; // 8

    cout << a.size() << '\n'; // 8
    cout << a.dim1() << "\n\n"; // 8

    int i = 4;
    int n = 7;

    a = i; // assigns 4 to every element in a
    a += n; // adds 7 to every element in a
   
    a1 = a - 4;

    cout << a << "\n\n"; // {11 11 11 11 11 11 11 11}

    cout << a1 << "\n\n"; // {7 7 7 7 7 7 7 7 }

    a.slice(i) = 2; // assigs 22to a(4:end)
    cout << a << "\n\n"; // {11 11 11 11 2 2 2 2 }

    // a 2-element slice from a[3] to a[3+2-1] (a[4])
    cout << a.slice(3, 2) << "\n\n"; // {11 2 2 2 2}

    // assign first half of a1 to second half of a
    a.slice(4, 4) = a1.slice(0, 4);
    cout << a << "\n\n"; // {11 11 11 11 7 7 7 7}

    // assign first half of a to second half of a
    a.slice(4) = a.slice(0,4); //
    cout << a << "\n\n"; // {11 11 11 11 11 11 11 11}

    Matrix<int> a2 = a; // copy initialization
    a = a1; // copy assignment
    a *= 7; // scaling... multiply each element of a by 7
    a = 8;  // assign 8 to each element of a
    cout << a << '\n'; // {8 8 8 8 8 8 8 8}
    cout << a1 << '\n'; // {7 7 7 7 7 7 7 7}
    cout << a2 << "\n\n"; // {11 11 11 11 11 11 11 11}

    a.apply(square_in_place);
    cout << a << '\n'; // {64 64 64 64 64 64 64 64}

    a.apply(f2, -2);
    cout << a << "\n\n"; // {-128 -128 -128 -128 -128 -128 -128 -128}

    Matrix<int> b = apply(abs, a); // makes a new Matrix with b[i] = abs(a[i])
    cout << b << "\n\n"; // {128 128 128 128 128 128 128 128}

    b = a / 2;
    a /= -8 * 4;
    cout << a << '\n'; // {4 4 4 4 4 4 4 4}
    cout << b << "\n\n"; // {-64 -64 -64 -64 -64 -64 -64 -64}
     
    Matrix<double> x {10}; // 1D Matrix w/10 elements
    x = 10.;
    
    Matrix<double> y = apply(square_d, x);
    cout << x << '\n'; // {10 10 10 10 10 10 10 10 10 10}
    cout << y << "\n\n"; // {100 100 100 100 100 100 100 100 100 100}

    b = apply(scale, a, 7);
    x.apply(scale_in_place, 3.0);
    cout << b << '\n'; // {28 28 28 28 28 28 28 28}
    cout << x << "\n\n"; // {30 30 30 30 30 30 30 30 30 30}

    Matrix<int> a3 = scale_and_add(a, 8, a2); // fused multiply add
    double d = dot_product(x, y);
    cout << a3 << '\n'; // {43 43 43 43 43 43 43 43}
    cout << d << '\n'; // 30000

    return 0;
}

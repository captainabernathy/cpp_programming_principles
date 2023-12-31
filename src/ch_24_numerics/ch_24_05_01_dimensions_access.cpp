// program demonstrates how to access and operate on 1, 2, and 3 dimensional
// Matrix objects

#include <iostream> // for cout, cerr
#include <exception> // for exception
#include <numeric_utils/matrix_utils.hpp> // for Matrix<>

// function initializes a two-dimensional Matrix of ints
void init(Numeric_lib::Matrix<int, 2>& a);

// function outputs a two-dimensional Matrix of ints
void print(Numeric_lib::Matrix<int, 2> const& a);

// function uses n1, n2, and n3 to create and perform operations on 1, 2, and
// 3 dimensional Matrix objects
void f(size_t n1, size_t n2, size_t n3);

// another function uses n1, n2, and n3 to create and perform operations on
// 1, 2, and 3 dimensional Matrix objects
void f1(size_t n1, size_t n2, size_t n3);


int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using namespace Numeric_lib;

        Matrix<int, 2> a{2, 3}; // a 2x3 Matrix

        init(a); // initialize a
        print(a); // output a

        f(10, 20, 30);
        f1(10, 20, 30);
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception\n";
        return 2;
    }

    return 0;
}

// function initializes a two-dimensional Matrix of ints
void init(Numeric_lib::Matrix<int, 2>& a)
{
    for (size_t i = 0; i < a.dim1(); i++)
        for (size_t j = 0; j < a.dim2(); j++)
            a(i, j) = 10 * i + j;
}

// function outputs a two-dimensional Matrix of ints
void print(Numeric_lib::Matrix<int, 2> const& a)
{
    for (size_t i = 0; i < a.dim1(); i++)
    {
        for (size_t j = 0; j < a.dim2(); j++)
            std::cout << a(i, j) << '\t';
        std::cout << '\n';
    }
}

// function uses n1, n2, and n3 to create and perform operations on 1, 2, and
// 3 dimensional Matrix objects
void f(size_t n1, size_t n2, size_t n3)
{
    using namespace Numeric_lib;
    using std::cout;

    Matrix<double, 1> ad1 {n1}; // 1D Matrix of doubles
    Matrix<int> ai1 {n1}; // 1D Matrix of ints
    
    cout << ad1 << "\n\n";
    cout << ai1 << "\n\n";

    // access with () or []
    ad1(7) = 77.7;
    ad1[8] = 88.8;

    ai1(7) = 7;
    ai1[8] = 8;

    cout << ad1 << "\n\n";
    cout << ai1 << "\n\n";

    Matrix<double, 2> ad2 {n1, n2}; // 2D Matrix of doubles
    Matrix<double, 3> ad3 {n1, n2, n3}; // 3D Matrix of doubles

    // access with () or []
    ad2(3, 4) = 7.5;
    ad2[3][5] = ad2(3, 4) + 1.0;
    cout << ad2 << "\n\n";

    ad3(3, 4, 5) = 9.2;
    ad3[3][4][6] = ad3(3, 4, 5) * 2.0;

    cout << ad3[3] << "\n";
}

// another function uses n1, n2, and n3 to create and perform operations on
// 1, 2, and 3 dimensional Matrix objects
void f1(size_t n1, size_t n2, size_t n3)
{
    using namespace Numeric_lib;
    using std::exception;
    using std::cerr;
    using std::cout;

    // Matrix<int, 0> ai0; // error... attempt to used deleted constructor

    Matrix<int, 1> ai {5}; // 1D Matrix of ints
    Matrix<double> ad1 {5}; // 1D Matrix of doubles
        
    // ad1 = ai; // no matching operator=

    Matrix<double> ad11 {7}; // 1D Matrix of doubles

    try
    {
        ad1(7) = 0; // throws Matrix_error... out of range
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << "\n\n";
    }

    try
    {
        ad1 = ad11; // throws Matrix_error... different dimensions
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << "\n\n";
    }

    // Matrix<double, 2> ad2(n1); // no matching constructor... missing dim

    Matrix<double, 3> ad3 {n1, n2, n3};

    ad3[1][2][3] = 1.23;
    ad3(1, 3, 2) = ad3[1][2][3] * ad3(1, 2, 3);

    cout << ad3[1] << "\n\n";

    Matrix<double, 3> ad33(n1, n2, n3);
    ad33 = ad3; // ok

    cout << ad33[1] << "\n\n";
}

